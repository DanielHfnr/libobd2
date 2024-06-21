// ============================================================================
// C O P Y R I G H T
// ----------------------------------------------------------------------------
// \copyright (C) 2024 Daniel Hafner
// ============================================================================

#ifndef OBD2_CONNECTION_HANDLER_HPP
#define OBD2_CONNECTION_HANDLER_HPP

namespace obd2::connection
{

/// \brief Class that handles the connection to the phyiscal interface. Different interfaces are supported.
/// \tparam ConnectionType_T Interface type (serial, socket, ...).
template <typename ConnectionType_T>
class ConnectionHandler final
{

public:
    /// \brief
    ConnectionHandler() {}

    /// \brief
    bool connect()
    {
        return true;
    }
};

} // namespace obd2::connection

#endif // OBD2_CONNECTION_HANDLER_HPP