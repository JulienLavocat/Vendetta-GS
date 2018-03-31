//
//  Server.hpp
//  Vendetta Game Server
//
//  Created by Julien on 30/03/2018.
//  Copyright © 2018 TheBad. All rights reserved.
//

#ifndef Server_hpp
#define Server_hpp

//Platform detection step

#define PLATFORM_APPLE   0
#define PLATFORM_UNIX    1

#if defined(__APPLE__)
    #define PLATFORM PLATFORM_MAC
#else
    #define PLATFORM PLATFORM_UNIX
#endif

#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <string>
#include "threadpool.hpp"
#include "Packet.hpp"

class Server {
   
public:
    Server(int port);
    void run();
    ~Server();
private:
    int handle;
    bool isClosed;
    ThreadPool pool;
    void sendPacketTo(std::string packet, sockaddr_in dest);
    Packet receive();
    void processPacket(std::string data);
};

#endif /* Server_hpp */
