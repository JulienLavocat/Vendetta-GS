//
//  Packet.hpp
//  Vendetta Game Server
//
//  Created by Julien on 30/03/2018.
//  Copyright © 2018 TheBad. All rights reserved.
//

#ifndef Packet_hpp
#define Packet_hpp

#include <string>
#include <netinet/in.h>

class Packet {

public:
    Packet(std::string in, sockaddr_in from);
    std::string data;
    sockaddr_in address;
    
};

#endif /* Packet_hpp */
