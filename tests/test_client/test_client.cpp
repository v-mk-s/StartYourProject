#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "usecases.hpp"
#include "validation.hpp"
#include "utils.hpp"
#include "network.hpp"
#include "general.hpp"
#include "clientui.hpp"



// Alex /////////////////////////

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


// Vlad ///////////////////////////////////////////////////////////////////

// VALIDATION TESTS ///////////////////////////////////////////////////////////

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

TEST(VALIDAION, CORRECT_DESCRIPTION)
{
    std::string description = "We are developing interesting things";

    EXPECT_EQ(isValidDescription(description), true);
}

TEST(VALIDAION, INCORRECT_DESCRIPTION)
{
    std::string description = "Vlad#####!00";

    EXPECT_EQ(isValidDescription(description), false);
}

TEST(VALIDAION, CORRECT_PROJECTDESCRIPTION)
{
    std::string project_description = "Top top game)";

    EXPECT_EQ(isValidProjectDescription(project_description), true);
}

TEST(VALIDAION, INCORRECT_PROJECTDESCRIPTION)
{
    std::string project_description = "Vlad#####!00";

    EXPECT_EQ(isValidProjectDescription(project_description), false);
}

TEST(VALIDAION, CORRECT_REQUESTDESCRIPTION)
{
    std::string request_description = "I am ready.";

    EXPECT_EQ(isValidRequestDescription(request_description), true);
}

TEST(VALIDAION, INCORRECT_REQUESTDESCRIPTION)
{
    std::string request_description = "Vlad#####!00";

    EXPECT_EQ(isValidRequestDescription(request_description), false);
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

TEST(VALIDAION, CORRECT_DIVERSITY)
{
    int diversity = 75;

    EXPECT_EQ(isValidDiversity(diversity), true);
}

TEST(VALIDAION, INCORRECT_DIVERSITY)
{
    int diversity = 110;

    EXPECT_EQ(isValidDiversity(diversity), false);
}

TEST(VALIDAION, CORRECT_QUESTION)
{
    std::string question = "Where are you company?";

    EXPECT_EQ(isValidQuestion(question), true);
}

TEST(VALIDAION, INCORRECT_QUESTION)
{
    std::string question = "Vlad#####!00";

    EXPECT_EQ(isValidQuestion(question), false);
}

TEST(VALIDAION, CORRECT_SEARCH)
{
    std::string search = "pytorch ml project";

    EXPECT_EQ(isValidSearchData(search), true);
}

TEST(VALIDAION, INCORRECT_SEARCH)
{
    std::string search = "Vlad#####!00";

    EXPECT_EQ(isValidSearchData(search), false);
}

TEST(VALIDAION, CORRECT_AGEFROM)
{
    int age_from = 75;

    EXPECT_EQ(isValidAgeFrom(age_from), true);
}

TEST(VALIDAION, INCORRECT_AGEFROM)
{
    int age_from = -10;

    EXPECT_EQ(isValidAgeFrom(age_from), false);
}

TEST(VALIDAION, CORRECT_AGETO)
{
    int age_to = 65;

    EXPECT_EQ(isValidAgeTo(age_to), true);
}

TEST(VALIDAION, INCORRECT_AGETO)
{
    int age_to = -10;

    EXPECT_EQ(isValidAgeTo(age_to), false);
}

TEST(VALIDAION, CORRECT_LANGUAGE)
{
    std::string language = "english";

    EXPECT_EQ(isValidLanguage(language), true);
}

TEST(VALIDAION, INCORRECT_LANGUAGE)
{
    std::string language = "elgliasdfwl";

    EXPECT_EQ(isValidLanguage(language), false);
}

TEST(VALIDAION, CORRECT_USERNAME) {
    std::string username = "Vlad";

    EXPECT_EQ(isValidUsername(username), true);
}

TEST(VALIDAION, INCORRECT_USERNAME) {
    std::string username = "Vlad!00";

    EXPECT_EQ(isValidUsername(username), false);
}

TEST(VALIDAION, INCORRECT_USERNAME) {
    std::string username = "";

    EXPECT_EQ(isValidUsername(username), false);
}

TEST(VALIDAION, CORRECT_EMAIL) {
    std::string email = "vlad@gmail.com";

    EXPECT_EQ(isValidUsername(email), true);
}

TEST(VALIDAION, INCORRECT_EMAIL) {
    std::string email = "vladgmail.com";

    EXPECT_EQ(isValidUsername(email), false);
}

TEST(VALIDAION, INCORRECT_EMAIL) {
    std::string email = "vla_d@gma!il.com";

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

// USERCASE TESTS ///////////////////////////////////////////////////////////

TEST(USECASES, INPUT_SEARCH_CORRECT) {
    MainData search_data = {0};
    search_data.post_data = "post data";
    search_data.competition = 1;
    search_data.hackathon = 1;
    search_data.start_up = 1;
    search_data.age_from = 10;
    search_data.age_to = 75;
    search_data.language = "english";
    search_data.post_tags = {"torch", "python"};
    search_data.diversity = 99;
    MainUC usecase = {0};
    EXPECT_EQ(usecase.onSearchButton(search_data), noError);
}

TEST(USECASES, INPUT_SEARCH_INCORRECT) {
    MainData search_data = {0};
    search_data.post_data = "post data";
    search_data.competition = 1;
    search_data.hackathon = 1;
    search_data.start_up = 1;
    search_data.age_from = 10;
    search_data.age_to = 75;
    search_data.language = "english";
    search_data.post_tags = {"torch", "python"};
    search_data.diversity = -99;
    MainUC usecase = {0};
    EXPECT_EQ(usecase.onSearchButton(search_data), Error);
}

TEST(USECASES, INPUT_PUBLISHPOST_CORRECT)
{
    PublishPostData publish_post_data = {0};
    publish_post_data.project_name = "SYP";
    publish_post_data.team_name = "TORCH";
    publish_post_data.post_tags = {"torch", "python"};
    publish_post_data.teammates = {"Torch", "Tython"};
    publish_post_data.project_description = "Good project";
    PublishPostUC usecase = {0};
    EXPECT_EQ(usecase.onPublishPostButton(publish_post_data), noError);
}

TEST(USECASES, INPUT_PUBLISHPOST_INCORRECT)
{
    PublishPostData publish_post_data = {0};
    publish_post_data.project_name = "1SYP";
    publish_post_data.team_name = "TORCH";
    publish_post_data.post_tags = {"1torch", "python"};
    publish_post_data.teammates = {"Torch", "Tython"};
    publish_post_data.project_description = "2Good project";
    PublishPostUC usecase = {0};
    EXPECT_EQ(usecase.onPublishPostButton(publish_post_data), Error);
}

TEST(USECASES, INPUT_PUBLISHPOST_CORRECT)
{
    UserEditData user_edit_data = {0};
    user_edit_data.username = "vlamelni";
    user_edit_data.email = "vs@ma.ru";
    user_edit_data.name = "Python";
    user_edit_data.surname = "Tython";
    user_edit_data.description = "Good project";
    user_edit_data.password = "Go1324a!";
    UserEditUC usecase = {0};
    EXPECT_EQ(usecase.onUserEditButton(user_edit_data), noError);
}

TEST(USECASES, INPUT_NOTIFICATION_CORRECT)
{
    NotificationData notify_data = {0};
    notify_data.projects = {0};
    NotificationUC usecase = {0};
    EXPECT_EQ(usecase.onNotificationButton(notify_data), noError);
}

TEST(USECASES, INPUT_PUBLISHPOST_INCORRECT)
{
    UserEditData user_edit_data = {0};
    user_edit_data.username = "vlamelni";
    user_edit_data.email = "vs@m!a.ru";
    user_edit_data.name = "Python";
    user_edit_data.surname = "Tython";
    user_edit_data.description = "Go!@od project";
    user_edit_data.password = "Go1324a!";
    UserEditUC usecase = {0};
    EXPECT_EQ(usecase.onUserEditButton(user_edit_data), Error);
}

TEST(USECASES, INPUT_PUBLISHPOST_CORRECT)
{
    UserData user_data = {0};
    user_data.username = "vlamelni";
    user_data.email = "vs@ma.ru";
    user_data.name = "Python";
    user_data.surname = "Tython";
    user_data.description = "Good project";
    user_data.password = "Go1324a!";
    UserUC usecase = {0};
    EXPECT_EQ(usecase.onUserEditButton(user_data), noError);
}
