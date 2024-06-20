
#include "obd2/connection_handler.hpp"
#include <iostream>

int main()
{

    obd2::connection::ConnectionHandler connection_handler{};

    if (connection_handler.connect())
    {
        std::cout << "Connection successful" << std::endl;
    }
    else
    {
        std::cout << "Connection not successful" << std::endl;
    }

    return 0;
}