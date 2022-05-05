#include "handlers.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>


class MockLoginUC: public LoginUC {
 public:
    MOCK_METHOD1(checkUser, ErrorStatus(LoginData user));
};

TEST(LoginHandlerTests, HandleRequest) {
    // MockLoginUC login_uc;
    // LoginData user;
    // EXPECT_CALL(login_uc, checkUser(user)).Times(testing::AtLeast(1));

    // LoginHandler handler;
    // handler.Handle();
}
