#ifndef OBD2_CONNECTION_HANDLER_HPP
#define OBD2_CONNECTION_HANDLER_HPP

#include <string>

namespace obd2::connection
{

/// \brief
class ConnectionHandler
{

public:
    /// \brief
    ConnectionHandler();

    /// \brief
    bool connect();
};

} // namespace obd2::connection

#endif // OBD2_CONNECTION_HANDLER_HPP