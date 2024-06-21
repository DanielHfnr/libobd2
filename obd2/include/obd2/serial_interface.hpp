// ============================================================================
// C O P Y R I G H T
// ----------------------------------------------------------------------------
// \copyright (C) 2024 Daniel Hafner
// ============================================================================

#ifndef OBD2_SERIAL_INTERFACE_HPP
#define OBD2_SERIAL_INTERFACE_HPP

#include <string>

namespace obd2::connection
{

/// \brief
/// \tparam SerialPortType_T
template <typename SerialPortType_T>
class SerialInterface final
{

public:
    SerialInterface() = default;

    SerialInterface(const SerialInterface&) = delete;

    SerialInterface operator=(const SerialInterface&) = delete;

    SerialInterface(SerialInterface&&) = delete;

    SerialInterface operator=(SerialInterface&&) = delete;

    ~SerialInterface();

    /// \brief
    /// \param[in] device
    /// \retval true
    /// \retval false
    [[nodiscard]] bool openDevice(const std::string& device);

    /// \brief
    void closeDevice();

    /// \brief
    /// \retval true
    /// \retval false
    [[nodiscard]] bool isOpen() const;

private:
    /// \brief
    std::string m_current_device{};
    /// \brief
    SerialPortType_T m_serial_port{};
};

} // namespace obd2::connection

#include "obd2/serial_interface.inl"

#endif // OBD2_SERIAL_INTERFACE_HPP