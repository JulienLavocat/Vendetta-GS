//
//  Server.cpp
//  Vendetta Game Server
//
//  Created by Julien on 30/03/2018.
//  Copyright © 2018 TheBad. All rights reserved.
//

#include "Server.hpp"
#include <iostream>
#include <thread>

Server::Server(int port) :
    isClosed(false),
    pool(30)
{
    
    handle = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    
    if(handle <= 0) {
        std::cout << "Failed to create socket.\n";
        return;
    }
    
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    
    if(bind(handle, reinterpret_cast<sockaddr*>(&address), sizeof(sockaddr_in)) < 0) {
        std::cout << "Failed to bind socket\n";
        return;
    }
}

void Server::run() {
    
    while(!isClosed) {
        Packet data(receive());
        
        //Processing packet in a thread from pool
        pool.enqueue([] (Packet p) {
            
            
            
        }, data);
    }
}



Packet Server::receive() {
    std::cout << "Waiting for packet\n";
    char buffer[8192];
    sockaddr_in from;
    socklen_t fromLen = sizeof(from);
    recvfrom(handle, buffer, 8192, 0, reinterpret_cast<sockaddr*>(&from), &fromLen);
    std::string data(buffer);
    return Packet(data, from);
}

void Server::sendPacketTo(std::string packet, sockaddr_in dest) {
    sendto(handle, packet.c_str(), packet.size(), 0, reinterpret_cast<sockaddr*>(&dest), sizeof(dest));
}

Server::~Server() {
    
}
