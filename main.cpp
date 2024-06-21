// ============================================================================
// C O P Y R I G H T
// ----------------------------------------------------------------------------
// \copyright (C) 2024 Daniel Hafner
// ============================================================================

#include "obd2/serial_interface.hpp"

#include <iostream>

int main()
{

    obd2::connection::SerialInterface serial_interface{"/dev/pts/1"};

    if (serial_interface.openDevice())
    {
        std::cout << "Connection successful" << std::endl;
    }
    else
    {
        std::cout << "Connection not successful" << std::endl;
    }

    return 0;
}