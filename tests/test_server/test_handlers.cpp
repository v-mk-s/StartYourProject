#include "handlers.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>


class MockLoginUC: public LoginUC {
 public:
    MOCK_METHOD1(checkUserInDB, ErrorStatus(LoginData user));
};

TEST(LoginHandlerTests, HandleRequest) {
    MockLoginUC login_uc;
    LoginData user;
    EXPECT_CALL(login_uc, checkUserInDB(user)).Times(AtLeast(1));

    LoginHandler handler;
    // Request test_request = {RequestType::login, "username=dima&password=qwerty1234"};

    // EXPECT_EQ(Response::Type::done, handler.Handler(test_request));
}
