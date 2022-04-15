#include <gtest/gtest.h>
#include "../../client/validation.hpp"
#include "../../client/utils.hpp"
#include "../../client/client_uc/login.hpp"

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