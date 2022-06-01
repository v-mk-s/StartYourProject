#include "usecases.hpp"
#include "validation.hpp"
#include "utils.hpp"
#include "general.hpp"
#include "clientui.hpp"
#include <gtest/gtest.h>


// Alex /////////////////////////

TEST(VALID_USERNAME_TEST, CORRECT_USERNAME) {
    std::string username = "Alexey00";

    EXPECT_EQ(isValidUsername(username), true);
}

TEST(VALID_USERNAME_TEST, INCORRECT_USERNAME_FIRST) {
    std::string username = "Alexey!00";

    EXPECT_EQ(isValidUsername(username), false);
}

TEST(VALID_USERNAME_TEST, INCORRECT_USERNAME_SECOND) {
    std::string username = "";

    EXPECT_EQ(isValidUsername(username), false);
}

TEST(IS_VALID_EMAIL, CORRECT_EMAIL) {
    std::string email = "alexey@mail.ru";

    EXPECT_EQ(isValidEmail(email), true);
}

TEST(IS_VALID_EMAIL, INCORRECT_EMAIL_FIRST) {
    std::string email = "alexeymail.ru";

    EXPECT_EQ(isValidEmail(email), false);
}

TEST(IS_VALID_PASSWORD, INCORRECT_PASSWORD_FIRST) {
    // accept all types of symbols
    std::string password = "aLe_Xe!y123@mail.ru";

    EXPECT_EQ(isValidPassword(password), false);
}

TEST(IS_VALID_PASSWORD, INCORRECT_PASSWORD_SECOND) {
    // password should be more or equal than 8 symbols
    std::string password = "qww21";

    EXPECT_EQ(isValidPassword(password), false);
}

TEST(IS_VALID_TEAMMATES, CORRECT_TEAMMATES) {
    std::vector<std::string> teammates;
    teammates.push_back("alexey");
    teammates.push_back("vladd");

    EXPECT_EQ(isValidTeammates(teammates), true);
}

TEST(IS_VALID_TEAMMATES, INCORRECT_TEAMMATES) {
    std::vector<std::string> teammates;
    teammates.push_back("alexey");
    teammates.push_back("vlad#$");

    EXPECT_EQ(isValidTeammates(teammates), false);
}

TEST(IS_VALID_POST_TAGS, CORRECT_POST_TAGS) {
    std::vector<std::string> tags;
    tags.push_back("#alexey");
    tags.push_back("#vlad");

    EXPECT_EQ(isValidPostTags(tags), true);
}

TEST(IS_VALID_POST_TAGS, INCORRECT_POST_TAGS) {
    std::vector<std::string> tags;
    tags.push_back("#alexey");
    tags.push_back("vlad");

    EXPECT_EQ(isValidPostTags(tags), false);
}

TEST(IS_VALID_PROJECT_DESCRIPTION, CORRECT_INPUT) {
    std::string description = "qww21";

    EXPECT_EQ(isValidProjectDescription(description), true);
}




TEST(USECASES_LOGIN, INPUT_LOGIN_FIRST) {
    UserData cor_login;
    cor_login.username = "alexey19";
    cor_login.password = "asd2das4ad2";
    LoginUC usecase;
    EXPECT_EQ(usecase.onLoginButton(cor_login), ErrorStatus::no_error);
}

TEST(USECASES_LOGIN, INPUT_LOGIN_SECOND) {
    UserData incor_login;
    incor_login.username = "alexasd"; 
    incor_login.password = "asd2";
    LoginUC usecase;
    EXPECT_EQ(usecase.onLoginButton(incor_login), ErrorStatus::password_not_valid);
}

TEST(USECASES_REGISTER, INPUT_REGISTER_FIRST) {
    UserData cor_reg;
    cor_reg.email = "sklaa00@mail.ru";
    cor_reg.username = "alex";
    cor_reg.password = "asd2das4ad2";
    RegisterUC usecase;
    EXPECT_EQ(usecase.onRegisterButton(cor_reg), ErrorStatus::no_error);
}

TEST(USECASES_REGISTER, INPUT_REGISTER_SECOND) {
    UserData incor_reg;
    incor_reg.email = "sklaa00mail.ru";
    incor_reg.username = "alex324";
    incor_reg.password = "aad2";
    RegisterUC usecase;
    EXPECT_EQ(usecase.onRegisterButton(incor_reg), ErrorStatus::email_not_valid);
}


// Vlad ///////////////////////////////////////////////////////////////////


TEST(VALIDAION, CORRECT_NAME)
{
    std::string name = "Vlad";

    EXPECT_EQ(isValidName(name), true);
}

TEST(VALIDAION, INCORRECT_NAME)
{
    std::string name = "Vlad!00";

    EXPECT_EQ(isValidName(name), false);
}

TEST(VALIDAION, CORRECT_SURNAME)
{
    std::string surname = "Melnichuk";

    EXPECT_EQ(isValidSurname(surname), true);
}

TEST(VALIDAION, INCORRECT_SURNAME)
{
    std::string surname = "Vlad!00";

    EXPECT_EQ(isValidSurname(surname), false);
}



TEST(VALIDAION, CORRECT_PROJECT_DESCRIPTION)
{
    std::string project_description = "Top top game)";

    EXPECT_EQ(isValidProjectDescription(project_description), true);
}


TEST(VALIDAION, CORRECT_TEAMNAME)
{
    std::string team_name = "PyTorchki";

    EXPECT_EQ(isValidTeamName(team_name), true);
}

TEST(VALIDAION, INCORRECT_TEAMNAME)
{
    std::string team_name = "Vlad#####!00";

    EXPECT_EQ(isValidTeamName(team_name), false);
}

TEST(VALIDAION, CORRECT_PROJECTNAME)
{
    std::string project_name = "SYP";

    EXPECT_EQ(isValidProjectName(project_name), true);
}

TEST(VALIDAION, INCORRECT_PROJECTNAME)
{
    std::string project_name = "Vlad#####!00";

    EXPECT_EQ(isValidProjectName(project_name), false);
}



TEST(VALIDAION, INCORRECT_EMAIL_) {
    std::string email = "vladgmail.com";

    EXPECT_EQ(isValidUsername(email), false);
}

