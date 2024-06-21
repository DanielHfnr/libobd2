// ============================================================================
// C O P Y R I G H T
// ----------------------------------------------------------------------------
// \copyright (C) 2024 Daniel Hafner
// ============================================================================

#include "obd2/serial_interface.hpp"

#include <iostream>

namespace obd2::connection
{

SerialInterface::SerialInterface(const std::string& device)
    : m_current_device(device)
{
}

bool SerialInterface::openDevice()
{
    try
    {
        std::cout << "Opening current device: " << m_current_device << std::endl;
        m_serial_port.Open(m_current_device);
    }
    catch (const LibSerial::OpenFailed&)
    {
        std::cout << "Failed to open device!" << std::endl;

        return false;
    }

    return true;
}

} // namespace obd2::connection