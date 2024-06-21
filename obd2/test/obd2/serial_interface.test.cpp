// ============================================================================
// C O P Y R I G H T
// ----------------------------------------------------------------------------
// \copyright (C) 2024 Daniel Hafner
// ============================================================================

#include "obd2/serial_interface.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace obd2::connection
{

namespace test
{
class SerialPortInterfaceMock final
{
public:
    MOCK_METHOD(void, Open, (const std::string&) );
    MOCK_METHOD(void, Close, ());
    MOCK_METHOD(bool, IsOpen, (), (const));
};

} // namespace test

TEST(SerialInterface, OpenConnectionAlreadyOpen)
{
    test::SerialPortInterfaceMock serial_port_mock{};
    SerialInterface<test::SerialPortInterfaceMock> serial_interface{serial_port_mock};

    EXPECT_CALL(serial_port_mock, IsOpen()).WillRepeatedly(testing::Return(true));

    EXPECT_FALSE(serial_interface.openDevice(""));
}

TEST(SerialInterface, OpenConnectionSuccess)
{
    test::SerialPortInterfaceMock serial_port_mock{};
    SerialInterface<test::SerialPortInterfaceMock> serial_interface{serial_port_mock};

    EXPECT_CALL(serial_port_mock, IsOpen()).WillRepeatedly(testing::Return(false));
    EXPECT_CALL(serial_port_mock, Open("/test/device")).Times(1);

    EXPECT_TRUE(serial_interface.openDevice("/test/device"));
}

TEST(SerialInterface, OpenConnectionFailure)
{
    test::SerialPortInterfaceMock serial_port_mock{};
    SerialInterface<test::SerialPortInterfaceMock> serial_interface{serial_port_mock};

    EXPECT_CALL(serial_port_mock, IsOpen()).WillRepeatedly(testing::Return(false));
    EXPECT_CALL(serial_port_mock, Open("/test/device")).Times(1).WillRepeatedly(testing::Throw(std::exception()));

    EXPECT_FALSE(serial_interface.openDevice("/test/device"));
}

} // namespace obd2::connection
