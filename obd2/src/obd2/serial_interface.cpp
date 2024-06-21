// ============================================================================
// C O P Y R I G H T
// ----------------------------------------------------------------------------
// \copyright (C) 2024 Daniel Hafner
// ============================================================================

#include "obd2/serial_interface.hpp"

#include <iostream>

namespace obd2::connection
{

SerialInterface::~SerialInterface()
{
    if (isOpen())
    {
        closeDevice();
    }
}

bool SerialInterface::openDevice(const std::string& device)
{
    if (isOpen())
    {
        std::cout << "There is an open device. Please close the device first." << std::endl;
        return false;
    }

    try
    {
        std::cout << "Opening device: " << device << std::endl;
        m_serial_port.Open(device);
    }
    catch (const LibSerial::OpenFailed&)
    {
        std::cout << "Failed to open device!" << std::endl;

        return false;
    }

    m_current_device = device;

    return true;
}

void SerialInterface::closeDevice()
{
    m_serial_port.Close();
}

bool SerialInterface::isOpen() const
{
    return m_serial_port.IsOpen();
}

} // namespace obd2::connection