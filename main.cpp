//
//  main.cpp
//  Vendetta Game Server
//
//  Created by Julien on 30/03/2018.
//  Copyright © 2018 TheBad. All rights reserved.
//

#include <iostream>
#include "Server.hpp"

int main(int argc, const char * argv[]) {
    std::cout << "Starting Vendetta Game Server !\n";
    
    Server server(3000);
    server.run();
    
    std::cout << "Stopping server...\n";
    return 0;
}
