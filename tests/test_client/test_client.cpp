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

TEST(IS_VALID_EMAIL, INCORRECT_EMAIL_SECOND) {
    std::string email = "ale_xe!y@mail.ru";

    EXPECT_EQ(isValidEmail(email), false);
}

TEST(IS_VALID_PASSWORD, CORRECT_PASSWORD_FIRST) {
    // accept all types of symbols
    std::string password = "aLe_Xe!y123@mail.ru";

    EXPECT_EQ(isValidPassword(password), true);
}

TEST(IS_VALID_PASSWORD, CORRECT_PASSWORD_SECOND) {
    // password should be more or equal than 8 symbols
    std::string password = "qweqw21";

    EXPECT_EQ(isValidPassword(password), true);
}

TEST(USECASES_LOGIN, INPUT_LOGIN_FIRST) {
    LoginData cor_login = {0};
    cor_login.username = "alex";
    cor_login.password = "asd2das4ad2";
    LoginUC usecase;
    EXPECT_EQ(usecase.onLoginButton(cor_login), ErrorStatus::no_error);
}

TEST(USECASES_LOGIN, INPUT_LOGIN_SECOND) {
    LoginData incor_login = {0};
    incor_login.username = "alexasd"; 
    incor_login.password = "asd2";
    LoginUC usecase;
    EXPECT_EQ(usecase.onLoginButton(incor_login), ErrorStatus::no_error);
}

TEST(USECASES_REGISTER, INPUT_REGISTER_FIRST) {
    RegisterData cor_reg = {0};
    cor_reg.email = "sklaa00@mail.ru";
    cor_reg.username = "alex";
    cor_reg.password = "asd2das4ad2";
    RegisterUC usecase;
    EXPECT_EQ(usecase.onRegisterButton(cor_reg), ErrorStatus::no_error);
}

TEST(USECASES_REGISTER, INPUT_REGISTER_SECOND) {
    RegisterData incor_reg = {0};
    incor_reg.email = "sklaa00mail.ru";
    incor_reg.username = "alex!";
    incor_reg.password = "aad2";
    RegisterUC usecase;
    EXPECT_EQ(usecase.onRegisterButton(incor_reg), ErrorStatus::no_error);
}

TEST(USECASES_REQ_TO_PROJ, CORRECT) {
    ProjectData request;
    request.project_name = "the best project";
    request.team_name = "bestTeam";

    std::vector<std::string> post_tags;
    post_tags.push_back("#team");
    post_tags.push_back("#project");
    request.post_tags = post_tags;

    std::vector<std::string> teammates;
    teammates.push_back("Alexey");
    teammates.push_back("Vladislav");
    teammates.push_back("Ilya");
    teammates.push_back("Daniil");
    request.teammates = teammates;

    // request.diversity = 77;

    request.project_description = "dasdasd";
    request.request_description = "asdasdasd";

    ProjectUC usecase;
    EXPECT_EQ(usecase.onRequestToProjectButton(request), ErrorStatus::no_error);
}

TEST(USECASES_REQ_TO_PROJ, INCORRECT_PROJ_NAME) {
    ProjectData request;
    request.project_name = "";
    request.team_name = "bestTeam";

    std::vector<std::string> post_tags;
    post_tags.push_back("#team");
    post_tags.push_back("#project");
    request.post_tags = post_tags;

    std::vector<std::string> teammates;
    teammates.push_back("Alexey");
    teammates.push_back("Vladislav");
    teammates.push_back("Ilya");
    teammates.push_back("Daniil");
    request.teammates = teammates;

    // request.diversity = 77;

    request.project_description = "dasdasd";
    request.request_description = "asdasdasd";

    ProjectUC usecase;
    EXPECT_EQ(usecase.onRequestToProjectButton(request), ErrorStatus::project_name_not_valid);
}

TEST(USECASES_REQ_TO_PROJ, INCORRECT_TEAM_NAME) {
    ProjectData request;
    request.project_name = "0dfghf";
    request.team_name = "bestTeamsdTooLongNameeeeee";

    std::vector<std::string> post_tags;
    post_tags.push_back("#team");
    post_tags.push_back("#project");
    request.post_tags = post_tags;

    std::vector<std::string> teammates;
    teammates.push_back("Alexey");
    teammates.push_back("Vladislav");
    teammates.push_back("Ilya");
    teammates.push_back("Daniil");
    request.teammates = teammates;

    // request.diversity = 77;

    request.project_description = "dasdasd";
    request.request_description = "asdasdasd";

    ProjectUC usecase;
    EXPECT_EQ(usecase.onRequestToProjectButton(request), ErrorStatus::team_name_not_valid);
}

TEST(USECASES_REQ_TO_PROJ, INCORRECT_POST_TAGS) {
    ProjectData request;
    request.project_name = "";
    request.team_name = "bestTeamsdT";

    std::vector<std::string> post_tags;
    post_tags.push_back("#team!@");
    post_tags.push_back("#pro$ject");
    request.post_tags = post_tags;

    std::vector<std::string> teammates;
    teammates.push_back("Alexey");
    teammates.push_back("Vladislav");
    teammates.push_back("Ilya");
    teammates.push_back("Daniil");
    request.teammates = teammates;

    // request.diversity = 77;

    request.project_description = "dasdasd";
    request.request_description = "asdasdasd";

    ProjectUC usecase;
    EXPECT_EQ(usecase.onRequestToProjectButton(request), ErrorStatus::post_tags_not_valid);
}

TEST(USECASES_REQ_TO_PROJ, INCORRECT_TEAMMATES) {
    ProjectData request;
    request.project_name = "";
    request.team_name = "bestTeamsdT";

    std::vector<std::string> post_tags;
    post_tags.push_back("#team");
    post_tags.push_back("#project");
    request.post_tags = post_tags;

    std::vector<std::string> teammates;
    teammates.push_back("");
    teammates.push_back("Vladislav");
    teammates.push_back("Ilya");
    teammates.push_back("Daniil");
    request.teammates = teammates;

    // request.diversity = 77;

    request.project_description = "dasdasd";
    request.request_description = "asdasdasd";

    ProjectUC usecase;
    EXPECT_EQ(usecase.onRequestToProjectButton(request), ErrorStatus::teammates_not_valid);
}

TEST(USECASES_REQ_TO_PROJ, INCORRECT_PROJ_DESCRIPTION) {
    ProjectData request;
    request.project_name = "";
    request.team_name = "bestTeamsdT";

    std::vector<std::string> post_tags;
    post_tags.push_back("#team");
    post_tags.push_back("#project");
    request.post_tags = post_tags;

    std::vector<std::string> teammates;
    teammates.push_back("Alexey");
    teammates.push_back("Vladislav");
    teammates.push_back("Ilya");
    teammates.push_back("Daniil");
    request.teammates = teammates;

    // request.diversity = 77;

    request.project_description = "";
    request.request_description = "asdasdasd";

    ProjectUC usecase;
    EXPECT_EQ(usecase.onRequestToProjectButton(request), ErrorStatus::project_description_not_valid);
}

TEST(USECASES_REQ_TO_PROJ, INCORRECT_REQ_DESCRIPTION) {
    ProjectData request;
    request.project_name = "";
    request.team_name = "bestTeamsdT";

    std::vector<std::string> post_tags;
    post_tags.push_back("#team");
    post_tags.push_back("#project");
    request.post_tags = post_tags;

    std::vector<std::string> teammates;
    teammates.push_back("Alexey");
    teammates.push_back("Vladislav");
    teammates.push_back("Ilya");
    teammates.push_back("Daniil");
    request.teammates = teammates;

    // request.diversity = 77;

    request.project_description = "asdasd";
    request.request_description = "";

    ProjectUC usecase;
    EXPECT_EQ(usecase.onRequestToProjectButton(request), ErrorStatus::request_description_not_valid);
}

// no need tests for onGetDataButton (same)

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

// TEST(VALIDAION, CORRECT_AGEFROM)
// {
//     int age_from = 75;

//     EXPECT_EQ(isValidAgeToFrom(age_from), true);
// }

// TEST(VALIDAION, INCORRECT_AGEFROM)
// {
//     int age_from = -10;

//     EXPECT_EQ(isValidAgeToFrom(age_from), false);
// }

// TEST(VALIDAION, CORRECT_AGETO)
// {
//     int age_to = 65;

//     EXPECT_EQ(isValidAgeTo(age_to), true);
// }

// TEST(VALIDAION, INCORRECT_AGETO)
// {
//     int age_to = -10;

//     EXPECT_EQ(isValidAgeTo(age_to), false);
// }

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

TEST(VALIDAION, INCORRECT_EMAIL_) {
    std::string email = "vladgmail.com";

    EXPECT_EQ(isValidUsername(email), false);
}


// USERCASE TESTS ///////////////////////////////////////////////////////////

// discuss post_data
TEST(USECASES, INPUT_SEARCH_CORRECT) {
    SearchData search_data = {0};
    // search_data.post_data = "post data";
    search_data.competition = 1;
    search_data.hackathon = 1;
    search_data.start_up = 1;
    search_data.age_from = 10;
    search_data.age_to = 75;
    search_data.language = "english";
    search_data.post_tags = {"torch", "python"};
    search_data.diversity = 99;
    MainUC usecase;
    EXPECT_EQ(usecase.onSearchButton(search_data), ErrorStatus::no_error);
}

// all commended tests: add ErrorStatus to utils.hpp

// TEST(USECASES, INPUT_SEARCH_INCORRECT) {
//     SearchData search_data = {0};
//     search_data.post_data = "post data";
//     search_data.competition = 1;
//     search_data.hackathon = 1;
//     search_data.start_up = 1;
//     search_data.age_from = 10;
//     search_data.age_to = 75;
//     search_data.language = "english";
//     search_data.post_tags = {"torch", "python"};
//     search_data.diversity = -99;
//     MainUC usecase;
//     EXPECT_EQ(usecase.onSearchButton(search_data), ErrorStatus::);
// }

TEST(USECASES, INPUT_PUBLISHPOST_CORRECT_FIRST)
{
    PublishPostData publish_post_data;
    publish_post_data.project_name = "SYP";
    publish_post_data.team_name = "TORCH";
    publish_post_data.post_tags = {"torch", "python"};
    publish_post_data.teammates = {"Torch", "Tython"};
    publish_post_data.project_description = "Good project";
    PublishPostUC usecase;
    EXPECT_EQ(usecase.onPublishPostButton(publish_post_data), ErrorStatus::no_error);
}

// check
// TEST(USECASES, INPUT_PUBLISHPOST_INCORRECT_SECOND)
// {
//     PublishPostData publish_post_data = {0};
//     publish_post_data.project_name = "1SYP";
//     publish_post_data.team_name = "TORCH";
//     publish_post_data.post_tags = {"1torch", "python"};
//     publish_post_data.teammates = {"Torch", "Tython"};
//     publish_post_data.project_description = "2Good project";
//     PublishPostUC usecase;
//     EXPECT_EQ(usecase.onPublishPostButton(publish_post_data), ErrorStatus::);
// }

TEST(USECASES, INPUT_PUBLISHPOST_CORRECT_SECOND)
{
    UserEditData user_edit_data;
    user_edit_data.username = "vlamelni";
    user_edit_data.email = "vs@ma.ru";
    user_edit_data.name = "Python";
    user_edit_data.surname = "Tython";
    user_edit_data.description = "Good project";
    user_edit_data.password = "Go1324a!";
    UserEditUC usecase;
    EXPECT_EQ(usecase.onUserEditButton(user_edit_data), ErrorStatus::no_error);
}

TEST(USECASES, INPUT_NOTIFICATION_CORRECT)
{
    NotificationData notify_data = {0};
    notify_data.projects = {0};
    NotificationUC usecase;
    EXPECT_EQ(usecase.onNotificationButton(notify_data), ErrorStatus::no_error);
}

// TEST(USECASES, INPUT_PUBLISHPOST_INCORRECT_FIRST)
// {
//     UserEditData user_edit_data = {0};
//     user_edit_data.username = "vlamelni";
//     user_edit_data.email = "vs@m!a.ru";
//     user_edit_data.name = "Python";
//     user_edit_data.surname = "Tython";
//     user_edit_data.description = "Go!@od project";
//     user_edit_data.password = "Go1324a!";
//     UserEditUC usecase;
//     EXPECT_EQ(usecase.onUserEditButton(user_edit_data), ErrorStatus::);
// }

TEST(USECASES, INPUT_PUBLISHPOST_CORRECT_THIRD)
{
    UserData user_data = {0};
    user_data.username = "vlamelni";
    user_data.email = "vs@ma.ru";
    user_data.name = "Python";
    user_data.surname = "Tython";
    user_data.description = "Good project";
    user_data.password = "Go1324a!";
    UserUC usecase;
    EXPECT_EQ(usecase.onUserEditButton(user_data), ErrorStatus::no_error);
}
