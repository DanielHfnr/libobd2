// ============================================================================
// C O P Y R I G H T
// ----------------------------------------------------------------------------
// \copyright (C) 2024 Daniel Hafner
// ============================================================================

#ifndef OBD2_SERIAL_INTERFACE_HPP
#define OBD2_SERIAL_INTERFACE_HPP

#include <libserial/SerialPort.h>

#include <string>

namespace obd2::connection
{

/// \brief
class SerialInterface
{

public:
    /// \brief
    SerialInterface(const std::string& device);

    bool openDevice();

private:
    std::string m_current_device{};
    LibSerial::SerialPort m_serial_port{};
};

} // namespace obd2::connection

#endif // OBD2_SERIAL_INTERFACE_HPP