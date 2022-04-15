#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "../../client/validation.hpp"
#include "../../client/utils.hpp"
#include "../../client/usecases.hpp"

TEST(LOGIN_USE_CASE, GET_CORRECT_LOGIN_DATA) {
    // std::string username = "alexey";
    // std::string password = "alexey19092000";

    // LoginData pushLoginButton(std::string& username, std::string& password);

    // LoginData result = pushLoginButton(username, password);

    // EXPECT_EQ()

}

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
    LoginData cor_login = { .username = "alex",
                        .password = "asd2das4ad2"}
    LoginData login = {0};
    MockLoginUC mock_login_uc;
    EXPECT_CALL(mock_login_uc, onLoginButton(login).Times(AtLeast(1)));

    EXPECT_EQ(logic.username, cor_login.username);
    EXPECT_EQ(logic.password, cor_login.password);
}

TEST(USECASES, INPUT_LOGIN_SECOND) {
    LoginData incor_login = {   .username = "alexasd",
                                .password = "asd2"}
    LoginData login = {0};
    MockLoginUC mock_login_uc;
    EXPECT_CALL(mock_login_uc, onLoginButton(login).Times(AtLeast(1)));

    EXPECT_EQ(logic.username, incor_login.username);
    EXPECT_EQ(logic.password, incor_login.password);
}

TEST(USECASES, INPUT_REGISTER_FIRST) {
    RegisterData cor_reg = {    .email = "sklaa00@mail.ru",
                                .username = "alex",
                                .password = "asd2das4ad2"}
    RegisterData reg = {0};
    MockLoginUC mock_login_uc;
    EXPECT_CALL(mock_login_uc, onLoginButton(login).Times(AtLeast(1)));

    EXPECT_EQ(reg.email, incor_reg.email);
    EXPECT_EQ(reg.username, incor_reg.username);
    EXPECT_EQ(reg.password, incor_reg.password);
}

TEST(USECASES, INPUT_REGISTER_SECOND) {
    RegisterData incor_reg = {  .email = "sklaa00mail.ru",
                                .username = "alex!",
                                .password = "aad2"}
    MockLoginUC mock_login_uc;
    EXPECT_CALL(mock_login_uc, onLoginButton(login).Times(AtLeast(1)));

    EXPECT_EQ(reg.email, incor_reg.email);
    EXPECT_EQ(reg.username, incor_reg.username);
    EXPECT_EQ(reg.password, incor_reg.password);
}
