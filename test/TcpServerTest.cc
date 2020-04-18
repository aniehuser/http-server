#include "TcpServer.h"
#include "gtest/gtest.h"
#include <stdint.h>


TEST(WrapperDeathTest, Close) {
    uint8_t unexpected_exit = -1;
    EXPECT_EXIT(Close(-1), ::testing::ExitedWithCode(unexpected_exit), "");
    EXPECT_EXIT(Close(-200), ::testing::ExitedWithCode(unexpected_exit), "");
}

TEST(WrapperDeathTest, SysExit) {
    uint8_t unexpected_exit = -1;
    EXPECT_EXIT(SysExit(0), ::testing::ExitedWithCode(0), "");
    EXPECT_EXIT(SysExit(-1), ::testing::ExitedWithCode(unexpected_exit), "");
    EXPECT_EXIT(SysExit(6), ::testing::ExitedWithCode(6), "");
}
