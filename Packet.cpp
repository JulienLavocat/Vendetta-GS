//
//  Packet.cpp
//  Vendetta Game Server
//
//  Created by Julien on 30/03/2018.
//  Copyright © 2018 TheBad. All rights reserved.
//

#include "Packet.hpp"

Packet::Packet(std::string in, sockaddr_in from) :
    data(in),
    address(from)
{
    
}
