// ============================================================================
// C O P Y R I G H T
// ----------------------------------------------------------------------------
// \copyright (C) 2024 Daniel Hafner
// ============================================================================

#ifndef OBD2_CONNECTION_HANDLER_HPP
#define OBD2_CONNECTION_HANDLER_HPP

#include <string>

namespace obd2::connection
{

/// \brief
class ConnectionHandler final
{

public:
    /// \brief
    ConnectionHandler();

    /// \brief
    bool connect();
};

} // namespace obd2::connection

#endif // OBD2_CONNECTION_HANDLER_HPP