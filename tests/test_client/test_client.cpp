#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "../../client/validation.hpp"
#include "../../client/utils.hpp"
#include "../../client/usecases.hpp"


// class MockLoginUC : public LoginUC {
// public:
//     MOCK_METHOD1(onLoginButton, ErrorStatus(LoginData user_data));
// };

// class MockRegisterUC : public RegisterUC {
// public:
//     MOCK_METHOD1(onRegisterButton, ErrorStatus(RegisterData user_data));
// };


TEST(VALIDAION, CORRECT_USERNAME) {
    std::string username = "Alexey00";

    EXPECT_EQ(isValidUsername(username), true);
}

TEST(VALIDAION, INCORRECT_USERNAME) {
    std::string username = "Alexey!00";

    EXPECT_EQ(isValidUsername(username), false);
}

TEST(VALIDAION, INCORRECT_USERNAME) {
    std::string username = "";

    EXPECT_EQ(isValidUsername(username), false);
}

TEST(VALIDAION, CORRECT_EMAIL) {
    std::string email = "alexey@mail.ru";

    EXPECT_EQ(isValidUsername(email), true);
}

TEST(VALIDAION, INCORRECT_EMAIL) {
    std::string email = "alexeymail.ru";

    EXPECT_EQ(isValidUsername(email), false);
}

TEST(VALIDAION, INCORRECT_EMAIL) {
    std::string email = "ale_xe!y@mail.ru";

    EXPECT_EQ(isValidUsername(email), false);
}

TEST(VALIDAION, CORRECT_PASSWORD) {
    // accept all types of symbols
    std::string password = "aLe_Xe!y123@mail.ru";

    EXPECT_EQ(isValidUsername(password), true);
}

TEST(VALIDAION, CORRECT_PASSWORD) {
    // password should be more or equal than 8 symbols
    std::string password = "qweqw21";

    EXPECT_EQ(isValidUsername(password), false);
}

TEST(USECASES, INPUT_LOGIN_FIRST) {
    LoginData cor_login = {0};
    cor_login.username = "alex";
    cor_login.password = "asd2das4ad2";
    LoginUC usecase = {0};
    EXPECT_EQ(usecase.onLoginButton(cor_login), noError);
}

TEST(USECASES, INPUT_LOGIN_SECOND) {
    LoginData incor_login = {0};
    incor_login.username = "alexasd"; 
    incor_login.password = "asd2";
    LoginUC usecase = {0};
    EXPECT_EQ(usecase.onLoginButton(incor_login), noError);
}

TEST(USECASES, INPUT_REGISTER_FIRST) {
    RegisterData cor_reg = {0};
    cor_reg.email = "sklaa00@mail.ru";
    cor_reg.username = "alex";
    cor_reg.password = "asd2das4ad2";
    RegisterUC reg = {0};
    EXPECT_EQ(usecase.onLoginButton(cor_reg), noError);
}

TEST(USECASES, INPUT_REGISTER_SECOND) {
    RegisterData incor_reg = {0};
    incor_reg.email = "sklaa00mail.ru";
    incor_reg.username = "alex!";
    incor_reg.password = "aad2";
    RegisterUC reg = {0};
    EXPECT_EQ(usecase.onLoginButton(incor_reg), noError);
}
