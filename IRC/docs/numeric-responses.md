# IRC Numeric Responses

## Overview

IRC servers communicate with clients using numeric responses to indicate success, failure, and informational messages. This document provides a comprehensive reference for all numeric responses implemented in this IRC server.

## Response Format

Numeric responses follow this general format:
```
:<server> <numeric> <target> <parameters> :<message>
```

For example:
```
:irc.example.com 001 alice :Welcome to the IRC Network, alice!user@host
```

## Response Categories

- [Registration Responses](#registration-responses) (001-099)
- [Command Responses](#command-responses) (200-399)
- [Error Responses](#error-responses) (400-599)
- [Channel Responses](#channel-specific-responses) (300-399)
- [Server Specific Responses](#server-specific-responses) (200-299)

## Registration Responses

These responses are sent to clients during the registration process.

### RPL_WELCOME (001)

Sent when a client successfully completes registration.

**Format:** `:<server> 001 <nick> :Welcome to the Internet Relay Network <nick>!<user>@<host>`

**Usage in code:**
```cpp
// In IRCServer::processRegistration
void IRCServer::processRegistration(IRCUser* user) {
    // ...registration checks...
    
    // Send welcome messages
    user->send(":" + this->_serverName + " 001 " + user->getNickname() + 
               " :Welcome to the Internet Relay Network " + 
               user->getNickname() + "!" + user->getUsername() + "@" + 
               user->getHostname() + "\r\n");
}
```

### RPL_YOURHOST (002)

Information about the server the client is connected to.

**Format:** `:<server> 002 <nick> :Your host is <server>, running version <version>`

**Usage in code:**
```cpp
user->send(":" + this->_serverName + " 002 " + user->getNickname() + 
           " :Your host is " + this->_serverName + 
           ", running version " + SERVER_VERSION + "\r\n");
```

### RPL_CREATED (003)

When the server was created/started.

**Format:** `:<server> 003 <nick> :This server was created <date>`

**Usage in code:**
```cpp
user->send(":" + this->_serverName + " 003 " + user->getNickname() + 
           " :This server was created " + this->_creationDate + "\r\n");
```

### RPL_MYINFO (004)

Server information about supported user/channel modes.

**Format:** `:<server> 004 <nick> <server> <version> <user_modes> <channel_modes>`

**Usage in code:**
```cpp
user->send(":" + this->_serverName + " 004 " + user->getNickname() + " " + 
           this->_serverName + " " + SERVER_VERSION + " io mtikl\r\n");
```

## Command Responses

Responses related to specific commands.

### RPL_UMODEIS (221)

Reports the current modes set for a user.

**Format:** `:<server> 221 <nick> <user_modes>`

**Usage in code:**
```cpp
// In ModeCommand::execute for user modes
void ModeCommand::execute() const {
    // ...
    
    // User mode query
    if (target == this->_user->getNickname() && this->_args.size() == 1) {
        std::string modeStr = "+";
        if (this->_user->hasMode("i")) modeStr += "i";
        if (this->_user->hasMode("o")) modeStr += "o";
        
        this->_server->sendNumericReply(this->_user, RPL_UMODEIS, modeStr);
    }
    
    // ...
}
```

### RPL_CHANNELMODEIS (324)

Reports the current modes set for a channel.

**Format:** `:<server> 324 <nick> <channel> <channel_modes> [mode_parameters]`

**Usage in code:**
```cpp
// In ModeCommand::execute for channel modes
void ModeCommand::execute() const {
    // ...
    
    // Channel mode query
    if (this->_args.size() == 1) {
        std::string modeStr = "+";
        if (channel->hasMode("i")) modeStr += "i";
        if (channel->hasMode("t")) modeStr += "t";
        if (channel->hasMode("k")) modeStr += "k";
        if (channel->hasMode("l")) modeStr += "l";
        
        this->_server->sendNumericReply(this->_user, RPL_CHANNELMODEIS, 
                                      channelName + " " + modeStr);
    }
    
    // ...
}
```

### RPL_NOTOPIC (331)

Indicates a channel has no topic set.

**Format:** `:<server> 331 <nick> <channel> :No topic is set`

**Usage in code:**
```cpp
// In TopicCommand::execute
void TopicCommand::execute() const {
    // ...
    
    // If no topic parameter, this is a topic query
    if (this->_args.size() == 1) {
        if (!channel->getTopic().empty()) {
            this->_server->sendNumericReply(this->_user, RPL_TOPIC, 
                                         channelName + " :" + channel->getTopic());
        } else {
            this->_server->sendNumericReply(this->_user, RPL_NOTOPIC, 
                                         channelName + " :No topic is set");
        }
    }
    
    // ...
}
```

### RPL_TOPIC (332)

Reports the topic for a channel.

**Format:** `:<server> 332 <nick> <channel> :<topic>`

**Usage in code:**
```cpp
// In JoinCommand::execute
void JoinCommand::execute() const {
    // ...
    
    // Send topic
    if (!channel->getTopic().empty()) {
        this->_server->sendNumericReply(this->_user, RPL_TOPIC, 
                                     channelName + " :" + channel->getTopic());
    }
    
    // ...
}
```

### RPL_NAMREPLY (353)

Lists the users in a channel.

**Format:** `:<server> 353 <nick> = <channel> :<users>`

**Usage in code:**
```cpp
// In IRCServer::sendNamesList
void IRCServer::sendNamesList(IRCUser* user, IRCChannel* channel) {
    std::string namesList = "";
    std::map<IRCUser*, bool> users = channel->getUsers();
    
    for (std::map<IRCUser*, bool>::iterator it = users.begin(); it != users.end(); ++it) {
        if (it->second) { // Operator
            namesList += "@";
        }
        namesList += it->first->getNickname() + " ";
    }
    
    user->send(":" + this->_serverName + " 353 " + user->getNickname() + 
              " = " + channel->getName() + " :" + namesList + "\r\n");
    user->send(":" + this->_serverName + " 366 " + user->getNickname() + 
              " " + channel->getName() + " :End of /NAMES list\r\n");
}
```

### RPL_ENDOFNAMES (366)

Indicates the end of a NAMES list.

**Format:** `:<server> 366 <nick> <channel> :End of /NAMES list`

**Usage in code:**
See example above in RPL_NAMREPLY.

## Error Responses

Error responses indicate something went wrong with a client request.

### ERR_NOSUCHNICK (401)

Indicates that a nickname doesn't exist.

**Format:** `:<server> 401 <nick> <target_nick> :No such nick/channel`

**Usage in code:**
```cpp
// In PrivmsgCommand::execute
void PrivmsgCommand::execute() const {
    // ...
    
    // If target is a user (no channel prefix)
    if (target[0] != '#' && target[0] != '&' && target[0] != '!' && target[0] != '+') {
        IRCUser* targetUser = this->_server->findUser(target);
        
        if (!targetUser) {
            this->_server->sendNumericReply(this->_user, ERR_NOSUCHNICK, 
                                         target + " :No such nick/channel");
            return;
        }
        
        // ...
    }
    
    // ...
}
```

### ERR_NOSUCHCHANNEL (403)

Indicates that a channel name doesn't exist.

**Format:** `:<server> 403 <nick> <channel> :No such channel`

**Usage in code:**
```cpp
// In JoinCommand::execute
void JoinCommand::execute() const {
    // ...
    
    // Validate channel name
    if (channelName[0] != '#' && channelName[0] != '&' && 
        channelName[0] != '+' && channelName[0] != '!') {
        this->_server->sendNumericReply(this->_user, ERR_NOSUCHCHANNEL, 
                                      channelName + " :No such channel");
        continue;
    }
    
    // ...
}
```

### ERR_CANNOTSENDTOCHAN (404)

Indicates that a message can't be sent to a channel.

**Format:** `:<server> 404 <nick> <channel> :Cannot send to channel`

**Usage in code:**
```cpp
// In PrivmsgCommand::execute
void PrivmsgCommand::execute() const {
    // ...
    
    // If target is a channel
    if (target[0] == '#' || target[0] == '&' || target[0] == '!' || target[0] == '+') {
        IRCChannel* channel = this->_server->findChannel(target);
        
        if (!channel) {
            this->_server->sendNumericReply(this->_user, ERR_NOSUCHCHANNEL, 
                                         target + " :No such channel");
            return;
        }
        
        if (!channel->hasUser(this->_user)) {
            this->_server->sendNumericReply(this->_user, ERR_CANNOTSENDTOCHAN, 
                                         target + " :Cannot send to channel");
            return;
        }
        
        // ...
    }
    
    // ...
}
```

### ERR_NONICKNAMEGIVEN (431)

Indicates that no nickname was given for a command requiring one.

**Format:** `:<server> 431 :No nickname given`

**Usage in code:**
```cpp
// In NickCommand::execute
void NickCommand::execute() const {
    // Check if command has arguments
    if (this->_args.empty()) {
        this->_server->sendNumericReply(this->_user, ERR_NONICKNAMEGIVEN, 
                                      ":No nickname given");
        return;
    }
    
    // ...
}
```

### ERR_ERRONEUSNICKNAME (432)

Indicates that a nickname contains invalid characters.

**Format:** `:<server> 432 <nick> <new_nick> :Erroneous nickname`

**Usage in code:**
```cpp
// In NickCommand::execute
void NickCommand::execute() const {
    // ...
    
    // Validate nickname format
    if (!isValidNickname(nickname)) {
        this->_server->sendNumericReply(this->_user, ERR_ERRONEUSNICKNAME, 
                                      nickname + " :Erroneous nickname");
        return;
    }
    
    // ...
}
```

### ERR_NICKNAMEINUSE (433)

Indicates that a nickname is already in use.

**Format:** `:<server> 433 <nick> <new_nick> :Nickname is already in use`

**Usage in code:**
```cpp
// In NickCommand::execute
void NickCommand::execute() const {
    // ...
    
    // Check if nickname is already in use
    if (this->_server->findUser(nickname) && this->_server->findUser(nickname) != this->_user) {
        this->_server->sendNumericReply(this->_user, ERR_NICKNAMEINUSE, 
                                      nickname + " :Nickname is already in use");
        return;
    }
    
    // ...
}
```

### ERR_NOTONCHANNEL (442)

Indicates that the user is not on the specified channel.

**Format:** `:<server> 442 <nick> <channel> :You're not on that channel`

**Usage in code:**
```cpp
// In PartCommand::execute
void PartCommand::execute() const {
    // ...
    
    if (!channel->hasUser(this->_user)) {
        this->_server->sendNumericReply(this->_user, ERR_NOTONCHANNEL, 
                                      channelName + " :You're not on that channel");
        continue;
    }
    
    // ...
}
```

### ERR_NEEDMOREPARAMS (461)

Indicates that a command didn't receive enough parameters.

**Format:** `:<server> 461 <nick> <command> :Not enough parameters`

**Usage in code:**
```cpp
// In ModeCommand::execute
void ModeCommand::execute() const {
    // Check if enough arguments
    if (this->_args.empty()) {
        this->_server->sendNumericReply(this->_user, ERR_NEEDMOREPARAMS, 
                                      "MODE :Not enough parameters");
        return;
    }
    
    // ...
}
```

### ERR_ALREADYREGISTRED (462)

Indicates that the client is already registered.

**Format:** `:<server> 462 <nick> :You may not reregister`

**Usage in code:**
```cpp
// In UserCommand::execute
void UserCommand::execute() const {
    // ...
    
    // Check if already registered
    if (this->_user->isRegistered()) {
        this->_server->sendNumericReply(this->_user, ERR_ALREADYREGISTRED, 
                                      ":You may not reregister");
        return;
    }
    
    // ...
}
```

### ERR_PASSWDMISMATCH (464)

Indicates that the provided password is incorrect.

**Format:** `:<server> 464 :Password incorrect`

**Usage in code:**
```cpp
// In IRCServer::processRegistration
void IRCServer::processRegistration(IRCUser* user) {
    // ...
    
    // Check if password is required and provided
    if (!this->_password.empty() && !user->isPassAccepted()) {
        user->send(":" + this->_serverName + " 464 * :Password required\r\n");
        return;
    }
    
    // ...
}
```

### ERR_CHANNELISFULL (471)

Indicates that a channel is full (user limit reached).

**Format:** `:<server> 471 <nick> <channel> :Cannot join channel (+l)`

**Usage in code:**
```cpp
// In JoinCommand::execute
void JoinCommand::execute() const {
    // ...
    
    if (channel->hasMode("l") && channel->getUserCount() >= channel->getUserLimit()) {
        this->_server->sendNumericReply(this->_user, ERR_CHANNELISFULL, 
                

