// ============================================================================
// C O P Y R I G H T
// ----------------------------------------------------------------------------
// \copyright (C) 2024 Daniel Hafner
// ============================================================================

#include "obd2/serial_interface.hpp"

#include <iostream>

namespace obd2::connection
{

template <typename SerialPortType_T>
SerialInterface<SerialPortType_T>::~SerialInterface()
{
    if (isOpen())
    {
        closeDevice();
    }
}

template <typename SerialPortType_T>
bool SerialInterface<SerialPortType_T>::openDevice(const std::string& device)
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
    catch (const std::exception&)
    {
        std::cout << "Failed to open device!" << std::endl;

        return false;
    }

    m_current_device = device;

    return true;
}

template <typename SerialPortType_T>
void SerialInterface<SerialPortType_T>::closeDevice()
{
    m_serial_port.Close();
}

template <typename SerialPortType_T>
bool SerialInterface<SerialPortType_T>::isOpen() const
{
    return m_serial_port.IsOpen();
}

} // namespace obd2::connection