# IRC Commands Reference

## Overview
This document provides a comprehensive reference for all IRC commands implemented in our server. For detailed implementation specifics, see [[command-system|Command System]] and [[message-flow|Message Flow]].

## Connection Commands
### PASS - Server Password
- **Usage**: `PASS <password>`
- **Description**: Set the connection password
- **Example**: `PASS yourpassword`
- **Required**: Yes, must be first command
- **See Also**: [[client-connection|Client Connection Flow]]

### NICK - Nickname
- **Usage**: `NICK <nickname>`
- **Description**: Set or change your nickname
- **Example**: `NICK void`
- **Limitations**: Must be unique on server

### USER - User Information
- **Usage**: `USER <username> <hostname> <servername> :<realname>`
- **Description**: Set your user information (required for registration)
- **Example**: `USER void localhost server :John Doe`
- **Note**: Required for registration

## Channel Commands
### JOIN - Join Channel
- **Usage**: 
  - `JOIN <channel>`
  - `JOIN <channel> <key>` (for password-protected channels)
- **Description**: Join a specified channel
- **Examples**: 
  - `JOIN #channel`
  - `JOIN #channel secretpass`
- **See Also**: [[channel-operations|Channel Operations]]

### PART - Leave Channel
- **Usage**: `PART <channel> [:<reason>]`
- **Description**: Leave a specified channel
- **Example**: `PART #channel :Goodbye!`

### TOPIC - Channel Topic
- **Usage**: `TOPIC <channel> [:<topic>]`
- **Description**: View or set channel topic
- **Examples**: 
  - View: `TOPIC #channel`
  - Set: `TOPIC #channel :New topic here`
- **Restrictions**: May require operator status (+o)

### MODE - Channel Modes
- **Usage**: `MODE <channel> <flags> [<args>]`
- **Description**: Set or remove channel modes
- **Common Modes**:
  - `+k <password>`: Set channel password
  - `+l <limit>`: Set user limit
  - `+t`: Only operators can change topic
  - `+i`: Make channel invite-only
  - `+o <nickname>`: Give operator status
- **Examples**:
  - `MODE #channel +k secret`
  - `MODE #channel +l 10`
  - `MODE #channel +o nickname`
- **See Also**: [[channel-operations|Channel Operations]]

### KICK - Remove User
- **Usage**: `KICK <channel> <nickname> [:<reason>]`
- **Description**: Kick a user from a channel
- **Example**: `KICK #channel user :Reason for kick`
- **Requires**: Channel operator status

### INVITE - Invite User
- **Usage**: `INVITE <nickname> <channel>`
- **Description**: Invite a user to a channel
- **Example**: `INVITE user #channel`
- **Note**: Required for invite-only channels (+i)

## Communication Commands
### PRIVMSG - Send Message
- **Usage**: `PRIVMSG <target> :<message>`
- **Description**: Send a message to a channel or user
- **Examples**: 
  - To channel: `PRIVMSG #channel :Hello everyone!`
  - To user: `PRIVMSG nickname :Private message`
- **See Also**: [[message-flow|Message Flow]]

### PING - Server Ping
- **Usage**: `PING <server>`
- **Description**: Ping the server to check connection
- **Example**: `PING server`
- **Note**: Server automatically responds with PONG

### QUIT - Disconnect
- **Usage**: `QUIT [:<message>]`
- **Description**: Disconnect from the server
- **Example**: `QUIT :Goodbye!`

## Registration Process
1. Connect to server
2. Send `PASS` command with server password
3. Set nickname using `NICK`
4. Provide user information with `USER`
5. Wait for registration confirmation
6. Join channels and begin communication

For implementation details, see [[server-implementation|Server Implementation]] and [[command-system|Command System]].
