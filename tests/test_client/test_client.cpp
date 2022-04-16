#include <gtest/gtest.h>
// #include "gmock/gmock.h"
#include "../../client/client_uc/usecases.hpp"
#include "../../client/basic/validation.hpp"
#include "../../client/utils.hpp"
#include "../../client/network/network.hpp"


TEST(VALID_USERNAME_TEST, CORRECT_USERNAME) {
    std::string username = "Alexey00";

    EXPECT_EQ(isValidUsername(username), 0);
}

TEST(VALID_USERNAME_TEST, INCORRECT_USERNAME_FIRST) {
    std::string username = "Alexey!00";

    EXPECT_EQ(isValidUsername(username), 0);
}

TEST(VALID_USERNAME_TEST, INCORRECT_USERNAME_SECOND) {
    std::string username = "";

    EXPECT_EQ(isValidUsername(username), 0);
}

TEST(IS_VALID_EMAIL, CORRECT_EMAIL) {
    std::string email = "alexey@mail.ru";

    EXPECT_EQ(isValidEmail(email), 0);
}

TEST(IS_VALID_EMAIL, INCORRECT_EMAIL_FIRST) {
    std::string email = "alexeymail.ru";

    EXPECT_EQ(isValidEmail(email), 0);
}

TEST(IS_VALID_EMAIL, INCORRECT_EMAIL_SECOND) {
    std::string email = "ale_xe!y@mail.ru";

    EXPECT_EQ(isValidEmail(email), 0);
}

TEST(IS_VALID_PASSWORD, CORRECT_PASSWORD_FIRST) {
    // accept all types of symbols
    std::string password = "aLe_Xe!y123@mail.ru";

    EXPECT_EQ(isValidPassword(password), 0);
}

TEST(IS_VALID_PASSWORD, CORRECT_PASSWORD_SECOND) {
    // password should be more or equal than 8 symbols
    std::string password = "qweqw21";

    EXPECT_EQ(isValidPassword(password), 0);
}

TEST(USECASES, INPUT_LOGIN_FIRST) {
    LoginData cor_login = {0};
    cor_login.username = "alex";
    cor_login.password = "asd2das4ad2";
    LoginUC usecase;
    EXPECT_EQ(usecase.onLoginButton(cor_login), ErrorStatus::noError);
}

TEST(USECASES, INPUT_LOGIN_SECOND) {
    LoginData incor_login = {0};
    incor_login.username = "alexasd"; 
    incor_login.password = "asd2";
    LoginUC usecase;
    EXPECT_EQ(usecase.onLoginButton(incor_login), ErrorStatus::noError);
}

TEST(USECASES, INPUT_REGISTER_FIRST) {
    RegisterData cor_reg = {0};
    cor_reg.email = "sklaa00@mail.ru";
    cor_reg.username = "alex";
    cor_reg.password = "asd2das4ad2";
    RegisterUC usecase;
    EXPECT_EQ(usecase.onRegisterButton(cor_reg), ErrorStatus::noError);
}

TEST(USECASES, INPUT_REGISTER_SECOND) {
    RegisterData incor_reg = {0};
    incor_reg.email = "sklaa00mail.ru";
    incor_reg.username = "alex!";
    incor_reg.password = "aad2";
    RegisterUC usecase;
    EXPECT_EQ(usecase.onRegisterButton(incor_reg), ErrorStatus::noError);
}
