#include "../../server/handlers/handlers.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>


class MockLoginUC: public LoginUC {
 public:
    MOCK_METHOD1(checkUserInDB, ErrorStatus(LoginData user));
};

TEST(LoginHandlerTests, HandleRequest) {
    MockLoginUC login_uc;
    LoginData user;
    EXPECT_CALL(login_uc, checkUserInDB(user)).Times(testing::AtLeast(1));

    LoginHandler handler;
    // handler.Handle();
}
