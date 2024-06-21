// ============================================================================
// C O P Y R I G H T
// ----------------------------------------------------------------------------
// \copyright (C) 2024 Daniel Hafner
// ============================================================================

#include "obd2/serial_interface.hpp"

#include <libserial/SerialPort.h>

#include <iostream>

int main()
{
    LibSerial::SerialPort serial_port{};

    obd2::connection::SerialInterface<LibSerial::SerialPort> serial_interface{serial_port};

    if (serial_interface.openDevice("/dev/pts/1"))
    {
        std::cout << "Connection successful" << std::endl;
    }
    else
    {
        std::cout << "Connection not successful" << std::endl;
    }

    if (serial_interface.isOpen())
    {
        std::cout << "Closing device" << std::endl;

        serial_interface.closeDevice();
    }

    return 0;
}