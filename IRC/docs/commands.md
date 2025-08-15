# IRC Commands Reference

## Overview

This document provides a comprehensive reference for all commands implemented in the IRC server. Each command entry includes the command syntax, parameters, examples, and implementation details.

## Command Categories

- [Connection Registration](#connection-registration-commands)
- [Channel Operations](#channel-operations-commands)
- [Messaging](#messaging-commands)
- [Server Queries](#server-query-commands)
- [Mode Commands](#mode-commands)
- [Connection Management](#connection-management-commands)

## Command Reference

### Connection Registration Commands

Commands used during the initial client connection and registration process.

#### PASS

Sets a connection password.

**Syntax:** `PASS <password>`

**Parameters:**
- `password`: The server password

**Example:**
```
PASS secretpassword
```

**Implementation:**
```cpp
void PassCommand::execute() const {
    // Check if enough arguments
    if (this->_args.empty()) {
        this->_server->sendNumericReply(this->_user, ERR_NEEDMOREPARAMS, "PASS :Not enough parameters");
        return;
    }
    
    // Check if already registered
    if (this->_user->isRegistered()) {
        this->_server->sendNumericReply(this->_user, ERR_ALREADYREGISTRED, ":You may not reregister");
        return;
    }
    
    // Set password and check against server password
    this->_user->setPassword(this->_args[0]);
    
    // Check if password matches server password
    if (this->_server->getPassword() == this->_user->getPassword()) {
        this->_user->setPassAccepted(true);
    }
    
    // Process registration if other requirements are met
    this->_server->processRegistration(this->_user);
}
```

#### NICK

Sets or changes the client's nickname.

**Syntax:** `NICK <nickname>`

**Parameters:**
- `nickname`: The desired nickname

**Example:**
```
NICK quvan-de
```

**Implementation:**
```cpp
void NickCommand::execute() const {
    // Check if enough arguments
    if (this->_args.empty()) {
        this->_server->sendNumericReply(this->_user, ERR_NONICKNAMEGIVEN, ":No nickname given");
        return;
    }
    
    std::string nickname = this->_args[0];
    
    // Validate nickname format
    if (!isValidNickname(nickname)) {
        this->_server->sendNumericReply(this->_user, ERR_ERRONEUSNICKNAME, nickname + " :Erroneous nickname");
        return;
    }
    
    // Check if nickname is already in use
    if (this->_server->findUser(nickname) && this->_server->findUser(nickname) != this->_user) {
        this->_server->sendNumericReply(this->_user, ERR_NICKNAMEINUSE, nickname + " :Nickname is already in use");
        return;
    }
    
    // Store old nickname for notifications
    std::string oldNickname = this->_user->getNickname();
    
    // Set the new nickname
    this->_user->setNickname(nickname);
    
    // Notify about nickname change if user was already registered
    if (!oldNickname.empty() && this->_user->isRegistered()) {
        std::string nickmsg = ":" + oldNickname + "!" + this->_user->getUsername() + "@" + 
                            this->_user->getHostname() + " NICK :" + nickname + "\r\n";
        
        // Notify user itself
        this->_user->send(nickmsg);
        
        // Notify users in common channels
        this->_server->notifyUserChannels(this->_user, nickmsg);
    }
    
    // Process registration if other requirements are met
    this->_server->processRegistration(this->_user);
}
```

#### USER

Specifies username, hostname, and realname.

**Syntax:** `USER <username> <hostname> <servername> :<realname>`

**Parameters:**
- `username`: Username
- `hostname`: Hostname (unused, use *)
- `servername`: Servername (unused, use *)
- `realname`: Real name of the user

**Example:**
```
USER alice * * :Quinten Van den berghe
```

**Implementation:**
```cpp
void UserCommand::execute() const {
    // Check if enough arguments
    if (this->_args.size() < 4) {
        this->_server->sendNumericReply(this->_user, ERR_NEEDMOREPARAMS, "USER :Not enough parameters");
        return;
    }
    
    // Check if already registered
    if (this->_user->isRegistered()) {
        this->_server->sendNumericReply(this->_user, ERR_ALREADYREGISTRED, ":You may not reregister");
        return;
    }
    
    // Set username and realname
    this->_user->setUsername(this->_args[0]);
    this->_user->setRealname(this->_args[3]);
    
    // Process registration if other requirements are met
    this->_server->processRegistration(this->_user);
}
```

#### CAP

Negotiates client capabilities (mostly ignored in this implementation).

**Syntax:** `CAP <subcommand> [:<capabilities>]`

**Parameters:**
- `subcommand`: LS, LIST, REQ, ACK, NAK, CLEAR, END
- `capabilities`: Optional list of capabilities

**Example:**
```
CAP LS
CAP END
```

**Implementation:**
```cpp
void CapCommand::execute() const {
    // We don't fully implement capabilities, just acknowledge common ones
    
    // Check if any arguments
    if (this->_args.empty()) {
        return;
    }
    
    std::string subcommand = this->_args[0];
    
    if (subcommand == "LS" || subcommand == "LIST") {
        // Send empty capability list
        this->_user->send(":" + this->_server->getServerName() + " CAP * LS :\r\n");
    } else if (subcommand == "REQ") {
        // Acknowledge any requested capabilities
        if (this->_args.size() > 1) {
            this->_user->send(":" + this->_server->getServerName() + " CAP * ACK :" + this->_args[1] + "\r\n");
        }
    } else if (subcommand == "END") {
        // End capability negotiation
        this->_server->processRegistration(this->_user);
    }
}
```

### Channel Operations Commands

Commands for creating, joining, and managing channels.

#### JOIN

Joins a channel or creates it if it doesn't exist.

**Syntax:** `JOIN <channel>[,<channel>...] [<key>[,<key>...]]`

**Parameters:**
- `channel`: Channel name(s) to join
- `key`: Optional channel key(s) (password)

**Example:**
```
JOIN #test
JOIN #private secretkey
```

**Implementation:**
```cpp
void JoinCommand::execute() const {
    // Check if user is registered
    if (!this->_user->isRegistered()) {
        this->_server->sendNumericReply(this->_user, ERR_NOTREGISTERED, ":You have not registered");
        return;
    }
    
    // Check if enough arguments
    if (this->_args.empty()) {
        this->_server->sendNumericReply(this->_user, ERR_NEEDMOREPARAMS, "JOIN :Not enough parameters");
        return;
    }
    
    std::string channelStr = this->_args[0];
    std::string keyStr = (this->_args.size() > 1) ? this->_args[1] : "";
    
    // Parse channel and key lists
    std::deque<std::string> channels = IRCUtilities::split(channelStr, ",");
    std::deque<std::string> keys = IRCUtilities::split(keyStr, ",");
    
    for (size_t i = 0; i < channels.size(); ++i) {
        std::string channelName = channels[i];
        std::string key = (i < keys.size()) ? keys[i] : "";
        
        // Validate channel name
        if (channelName[0] != '#' && channelName[0] != '&' && channelName[0] != '+' && channelName[0] != '!') {
            this->_server->sendNumericReply(this->_user, ERR_NOSUCHCHANNEL, channelName + " :No such channel");
            continue;
        }
        
        IRCChannel* channel = this->_server->findChannel(channelName);
        
        if (!channel) {
            // Create new channel
            channel = this->_server->createChannel(channelName);
            channel->addUser(this->_user, true);  // First user is operator
        } else {
            // Check channel modes
            if (channel->hasMode("k") && channel->getKey() != key) {
                this->_server->sendNumericReply(this->_user, ERR_BADCHANNELKEY, channelName + " :Cannot join channel (+k)");
                continue;
            }
            
            if (channel->hasMode("i") && !channel->isInvited(this->_user->getNickname())) {
                this->_server->sendNumericReply(this->_user, ERR_INVITEONLYCHAN, channelName + " :Cannot join channel (+i)");
                continue;
            }
            
            if (channel->hasMode("l") && channel->getUserCount() >= channel->getUserLimit()) {
                this->_server->sendNumericReply(this->_user, ERR_CHANNELISFULL, channelName + " :Cannot join channel (+l)");
                continue;
            }
            
            // Add user to channel
            channel->addUser(this->_user);
        }
        
        // Add channel to user's joined channels
        this->_user->joinChannel(channel);
        
        // Send join notification
        std::string joinMsg = ":" + this->_user->getNickname() + "!" + this->_user->getUsername() + "@" + 
                             this->_user->getHostname() + " JOIN " + channelName + "\r\n";
        this->_server->broadcast(channel, joinMsg);
        
        // Send topic
        if (!channel->getTopic().empty()) {
            this->_server->sendNumericReply(this->_user, RPL_TOPIC, channelName + " :" + channel->getTopic());
        } else {
            this->_server->sendNumericReply(this->_user, RPL_NOTOPIC, channelName + " :No topic is set");
        }
        
        // Send names list
        this->_server->sendNamesList(this->_user, channel);
    }
}
```

#### PART

Leaves a channel.

**Syntax:** `PART <channel>[,<channel>...] [:<reason>]`

**Parameters:**
- `channel`: Channel name(s) to leave
- `reason`: Optional part reason

**Example:**
```
PART #test
PART #channel1,#channel2 :Gone to lunch
```

**Implementation:**
```cpp
void PartCommand::execute() const {
    // Check if user is registered
    if (!this->_user->isRegistered()) {
        this->_server->sendNumericReply(this->_user, ERR_NOTREGISTERED, ":You have not registered");
        return;
    }
    
    // Check if enough arguments
    if (this->_args.empty()) {
        this->_server->sendNumericReply(this->_user, ERR_NEEDMOREPARAMS, "PART :Not enough parameters");
        return;
    }
    
    std::string channelStr = this->_args[0];
    std::string reason = (this->_args.size() > 1) ? this->_args[1] : "Leaving";
    
    // Parse channel list
    std::deque<std::string> channels = IRCUtilities::split(channelStr, ",");
    
    for (size_t i = 0; i < channels.size(); ++i) {
        std::string channelName = channels[i];
        IRCChannel* channel = this->_server->findChannel(channelName);
        
        if (!channel) {
            this->_server->sendNumericReply(this->_user, ERR_NOSUCHCHANNEL, channelName + " :No such channel");
            continue;
        }
        
        if (!channel->hasUser(this->_user)) {
            this->_server->sendNumericReply(this->_user, ERR_NOTONCHANNEL, channelName + " :You're not on that channel");
            continue;
        }
        
        // Send part notification
        std::string partMsg = ":" + this->_user->getNickname() + "!" + this->_user->getUsername() + "@" + 
                             this->_user->getHostname() + " PART " + channelName + " :" + reason + "\r\n";
        this->_server->broadcast(channel, partMsg);
        
        // Remove user from channel
        channel->removeUser(this->_user);
        this->_user->partChannel(channel);
        
        // Check if channel is empty
        if (channel->getUserCount() == 0) {
            this->_server->removeChannel(channelName);
        }
    }
}
```

#### TOPIC

Views or sets a channel topic.

**Syntax:** `TOPIC <channel> [:<topic>]`

**Parameters:**
- `channel`: Channel name
- `topic`: Optional new topic (if omitted, shows current topic)

**Example:**
```
TOPIC #test
TOPIC #test :Welcome to the test channel
```

**Implementation:**
```cpp
void TopicCommand::execute() const {
    // Check if user is registered
    if (!this->_user->isRegistered()) {
        this->_server->sendNumericReply(this->_user, ERR_NOTREGISTERED, ":You have not registered");
        return;
    }
    
    // Check if enough arguments
    if (this->_args.empty()) {
        this->_server->sendNumericReply(this->_user, ERR_NEEDMOREPARAMS, "TOPIC :Not enough parameters");
        return;
    }
    
    std::string channelName = this->_args[0];
    IRCChannel* channel = this->_server->findChannel(channelName);
    
    if (!channel) {
        this->_server->sendNumericReply(this->_user, ERR_NOSUCHCHANNEL, channelName + " :No such channel");
        return;
    }
    
    if (!channel->hasUser(this->_user)) {
        this->_server->sendNumericReply(this->_user, ERR_NOTONCHANNEL, channelName + " :You're not on that channel");
        return;
    }
    
    // If no topic parameter, this is a topic query
    if (this->_args.size() == 1) {
        if (!channel->getTopic().empty()) {
            this->_server->sendNumericReply(this->_user, RPL_TOPIC, channelName + " :" + channel->getTopic());
        } else {
            this->_server->sendNumericReply(this->_user, RPL_NOTOPIC, channelName + " :No

