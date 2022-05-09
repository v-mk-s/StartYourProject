#include "usecases.hpp"
#include "validation.hpp"
#include "client_utils.hpp"
#include "general.hpp"
#include "clientui.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

// using ::testing::AtLeast;
// using ::testing::Return;

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
    SearchData search_data = {0};
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
    SearchData search_data = {0};
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

// MOCK TESTS
// 

// class MockDB : public MainDataBase
// {
// public:
//     MOCK_METHOD(bool, InsertIntoPersonTable, (RegisterData & data));
//     MOCK_METHOD(bool, InsertIntoPostTable, ());
//     MOCK_METHOD(bool, InsertIntoRequestToPostTable, ());

//     MOCK_METHOD(bool, DeleteFromPostTable, ());
//     MOCK_METHOD(bool, DeleteFromPersonTable, (std::string & data));
//     MOCK_METHOD(bool, DeleteFromRequestToPostTable, (RequestToPostData & data));

//     MOCK_METHOD(bool, EditUserInPersonTable, (UserData & data));

//     MOCK_METHOD(bool, FindIntoPersonTable, (LoginData & data));

//     MOCK_METHOD(UserData, getUserProfile, (std::string & username));
// };

// TEST(LoginUCTest, GoodCase)
// {
//     MockDB database;
//     LoginData test_data = {"John_123-4", "qwerty1234"};
//     EXPECT_CALL(database, FindIntoPersonTable(test_data)).Times(1).WillOnce(Return(true));

//     LoginUC usecase(&database);

//     Message<std::string> msg = usecase.checkUser(test_data);
//     EXPECT_EQ(ErrorStatus::ok, msg.status);
//     EXPECT_TRUE(msg.data.length() != 0) << "Message: " << msg.data;
// }

// TEST(LoginUCTest, WrongName)
// {
//     MockDB database;
//     LoginData test_data = {"User.1/@?)", "1234qwerty"};
//     LoginUC usecase(&database);

//     EXPECT_CALL(database, FindIntoPersonTable(test_data)).Times(0);

//     Message<std::string> msg = usecase.checkUser(test_data);
//     EXPECT_EQ(ErrorStatus::wrong_data, msg.status);
//     EXPECT_EQ(WRONG_NAME, msg.data);
// }

// TEST(LoginUCTest, EmptyName)
// {
//     MockDB database;
//     LoginData test_data = {"", "1234qwerty"};
//     EXPECT_CALL(database, FindIntoPersonTable(test_data)).Times(0);

//     LoginUC usecase(&database);

//     Message<std::string> msg = usecase.checkUser(test_data);
//     EXPECT_EQ(ErrorStatus::wrong_data, msg.status);
//     EXPECT_EQ(WRONG_NAME, msg.data);
// }

// TEST(LoginUCTest, EmptyPassword)
// {
//     MockDB database;
//     LoginData test_data = {"Password", ""};
//     EXPECT_CALL(database, FindIntoPersonTable(test_data)).Times(0);

//     LoginUC usecase(&database);

//     Message<std::string> msg = usecase.checkUser(test_data);
//     EXPECT_EQ(ErrorStatus::wrong_data, msg.status);
//     EXPECT_EQ(WRONG_PASSWORD, msg.data);
// }

// TEST(RegisterUCTest, GoodCase)
// {
//     MockDB database;
//     RegisterData test_data = {"Jack", "1q2w3e4r5t6y", "email@mail.ru"};
//     EXPECT_CALL(database, InsertIntoPersonTable(test_data)).Times(1).WillOnce(Return(true));

//     RegisterUC usecase(&database);

//     Message<std::string> msg = usecase.addUser(test_data);
//     EXPECT_EQ(ErrorStatus::ok, msg.status);
//     EXPECT_EQ(msg.data.length(), 0) << "Message: " << msg.data;
// }

// TEST(RegisterUCTest, WrongEmail)
// {
//     MockDB database;
//     RegisterData test_data = {"Jack", "1q2w3e4r5t6y", "email.ru@sldfj"};
//     EXPECT_CALL(database, InsertIntoPersonTable(test_data)).Times(0);

//     RegisterUC usecase(&database);

//     Message<std::string> msg = usecase.addUser(test_data);
//     EXPECT_EQ(ErrorStatus::wrong_data, msg.status);
//     EXPECT_EQ(WRONG_EMAIL, msg.data);
// }

// TEST(EditProfileUCTest, GoodCase)
// {
//     MockDB database;
//     UserData test_data = {"Jack", "email@mail.ru", "Abc", "dfgh", "some text", "1234qwerty"};
//     EXPECT_CALL(database, EditUserInPersonTable(test_data)).Times(1).WillOnce(Return(true));

//     EditProfileUC usecase(&database);

//     Message<std::string> msg = usecase.editUserData(test_data);
//     EXPECT_EQ(ErrorStatus::ok, msg.status);
//     EXPECT_EQ(msg.data.length(), 0) << "Message: " << msg.data;
// }

// TEST(DelUserProfileUCTest, GoodCase)
// {
//     MockDB database;
//     std::string test_username = "abcdefg";
//     EXPECT_CALL(database, DeleteFromPersonTable(test_username)).Times(1).WillOnce(Return(true));

//     DelUserProfileUC usecase(&database);

//     Message<std::string> msg = usecase.delUserData(test_username);
//     EXPECT_EQ(ErrorStatus::ok, msg.status);
//     EXPECT_EQ(msg.data.length(), 0) << "Message: " << msg.data;
// }

// TEST(GetUserProfileUCTest, GoodCase)
// {
//     MockDB database;
//     std::string test_username = "abcdefg";
//     EXPECT_CALL(database, getUserProfile(test_username)).Times(1);

//     GetUserProfileUC usecase(&database);

//     Message<UserData> msg = usecase.getUserData(test_username);
//     EXPECT_EQ(ErrorStatus::ok, msg.status);
// }

// PostData post = {1, "проект", "классный проект", "Стартап", "PyTorchki"};
// RequestToPostData req = {1, 2, "Очень хочу к вам в команду"};

// TEST(EditPostTest, UC)
// {
//     MockDB db;
//     EXPECT_CALL(db, InsertIntoPostTable()).Times(AtLeast(1));
//     EXPECT_CALL(db, DeleteFromPostTable()).Times(AtLeast(1));
//     EditPost Test_1(&db);
//     EXPECT_EQ(Test_1.editPostToDB(post), ErrorStatus::ok);
// }

// TEST(SearchPostTest, UC)
// {
//     MockDB db;
//     SearchPost Test_1(&db);
//     EXPECT_EQ(Test_1.makePostSearch(post), ErrorStatus::ok);
// }

// TEST(SearchPersonTest, UC)
// {
//     MockDB db;
//     SearchPerson Test_1(&db);
//     EXPECT_EQ(Test_1.makePersonSearch("cool_username"), ErrorStatus::ok);
// }

// TEST(MakeRequestToPostTest, UC)
// {
//     MockDB db;
//     EXPECT_CALL(db, InsertIntoRequestToPostTable()).Times(AtLeast(1));
//     MakeRequestToPost Test_1(&db);
//     EXPECT_EQ(Test_1.makeReqToPost(req), ErrorStatus::ok);
// }

// TEST(DeletePostTest, UC)
// {
//     MockDB db;
//     EXPECT_CALL(db, DeleteFromPostTable()).Times(AtLeast(1));
//     DeletePost Test_1(&db);
//     EXPECT_EQ(Test_1.delPostData(1), ErrorStatus::ok);
// }

// TEST(AnswerTheRequestTest, UC)
// {
//     MockDB db;
//     AnswerTheRequest Test_1(&db);
//     EXPECT_EQ(Test_1.getAnswer(false, req), ErrorStatus::ok);
// }

// TEST(ShowNotificationsTest, UC)
// {
//     MockDB db;
//     ShowNotifications Test_1(&db);
//     EXPECT_EQ(Test_1.showAllNotifications(1), ErrorStatus::ok);
// }

// TEST(CreatePostTest, UC)
// {
//     MockDB db;
//     EXPECT_CALL(db, InsertIntoPostTable()).Times(AtLeast(1));
//     CreatePost Test_1(&db);
//     EXPECT_EQ(Test_1.addPostToDB(post), ErrorStatus::ok);
// }
