#include "server_usecases.hpp"
#include "database.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::AtLeast;
using ::testing::Return;





// class MockDB: public MainDataBase {
//  public:
//     MOCK_METHOD(bool, InsertIntoPersonTable, (UserData &data));
//     MOCK_METHOD(bool, InsertIntoPostTable, (ProjectData &data));
//     MOCK_METHOD(bool, InsertIntoRequestToPostTable, (RequestToPostData &data));

//     MOCK_METHOD(bool, DeleteFromPostTable, (int id));
//     MOCK_METHOD(bool, DeleteFromPersonTable, (int id));
//     MOCK_METHOD(bool, DeleteFromRequestToPostTable, (RequestToPostData &data));
//     MOCK_METHOD(bool, DelFromTableNotifications, (RequestToPostData &data));

//     MOCK_METHOD(bool, EditUserInPersonTable, (UserData &data));
//     MOCK_METHOD(bool, EditPostInPostTable, (ProjectData &data));
//     MOCK_METHOD(bool, EditRequestToPostTable, (RequestToPostData &data));

//     MOCK_METHOD(bool, FindIntoPersonByUsername, (std::string &username, UserData& data));
//     MOCK_METHOD(bool, FindIntoPersonByID, (int &id));
//     MOCK_METHOD(bool, FindIntoPostTable, (std::string &project_name, ProjectData& data));
//     MOCK_METHOD(NotificationData, FindRequestToPostTable, (int &user_id));
    
//     MOCK_METHOD(bool, InsertToken, (int id, std::string& token));
//     MOCK_METHOD(bool, CheckToken, (int id, std::string& token));
//     MOCK_METHOD(bool, DeleteToken, (int id));

//     // MOCK_METHOD(UserData, getUserProfile, (std::string &username));
//     // MOCK_METHOD(ProjectData, getPost, (std::string &project_name));
//     MOCK_METHOD(std::vector<ProjectData>, getMultiPost, (SearchData &data));
// };



// TEST(LoginUCTest, GoodCase) {
//     MockDB database;
//     UserData test_data;
//     test_data.id = 123;
//     test_data.username = "John_123-4";
//     test_data.password = "qwerty1234";
//     EXPECT_CALL(database, 
//                 FindIntoPersonByUsername(test_data.username, test_data)).Times(1).WillOnce(Return(true));
//     EXPECT_CALL(database,
//                 InsertToken(test_data.id, test_data.auth_token)).Times(1).WillOnce(Return(true));

//     LoginUC usecase(&database);

//     Message<UserData> msg = usecase.checkUser(test_data);
//     EXPECT_EQ(ResponseStatus::ok, msg.status);
//     EXPECT_TRUE(msg.data.auth_token.length() != 0) << "Message: " << msg.data; 
// }


// TEST(RegisterUCTest, GoodCase) {
//     MockDB database;
//     UserData test_data;
//     test_data.username = "John_123-4";
//     test_data.password = "qwerty1234";
//     test_data.email = "email@mail.ru";
//     EXPECT_CALL(database, InsertIntoPersonTable(test_data)).Times(1).WillOnce(Return(true));

//     RegisterUC usecase(&database);

//     Message<std::string> msg = usecase.addUser(test_data);
//     EXPECT_EQ(ResponseStatus::ok, msg.status);
//     EXPECT_EQ(msg.data.length(), 0) << "Message: " << msg.data;
// }

// TEST(EditProfileUCTest, GoodCase) {
//     MockDB database;
//     UserData test_data;
//     test_data.name = "Jack";
//     test_data.email = "email@mail.ru";
//     test_data.username = "Abc";
//     test_data.sur_name = "dfgh";
//     test_data.user_discription = "some text";
//     test_data.password = "1234qwerty";
//     EXPECT_CALL(database, EditUserInPersonTable(test_data)).Times(1).WillOnce(Return(true));

//     EditProfileUC usecase(&database);

//     Message<std::string> msg = usecase.editUserData(test_data);
//     EXPECT_EQ(ResponseStatus::ok, msg.status);
//     EXPECT_EQ(msg.data.length(), 0) << "Message: " << msg.data;
// }

// TEST(DelUserProfileUCTest, GoodCase) {
//     MockDB database;
//     UserData test_data;
//     test_data.id = 123;
//     EXPECT_CALL(database, DeleteFromPersonTable(test_data.id)).Times(1).WillOnce(Return(true));

//     DelUserProfileUC usecase(&database);

//     Message<std::string> msg = usecase.delUserData(test_data);
//     EXPECT_EQ(ResponseStatus::ok, msg.status);
//     EXPECT_EQ(msg.data.length(), 0) << "Message: " << msg.data;
// }

// TEST(GetUserProfileUCTest, GoodCase) {
//     MockDB database;
//     std::string test_username = "abcdefg";
//     EXPECT_CALL(database, getUserProfile(test_username)).Times(1);

//     GetUserProfileUC usecase(&database);

//     Message<UserData> msg = usecase.getUserData(test_username);
//     EXPECT_EQ(ResponseStatus::ok, msg.status);
// }


// ProjectData post;
// post.project_name = "project";
// post.team_name = "PyTorchki";
// post.post_tags = {"Python"};
// post.teammates {"Teammate"};
// post.project_description = "cool project";
// RequestToPostData req = {1,2, "cool project", "I really want to join your team", RequestToPostData::Status::unknown};

// TEST(EditPostTest, UC) {
//     MockDB db;
//     EXPECT_CALL(db, EditPostInPostTable(post)).Times(AtLeast(1)).WillOnce(Return(true));
//     EditPost Test_1(&db);
//     EXPECT_EQ(Test_1.editPostToDB(post), ResponseStatus::ok);
// }

// TEST(SearchPostTest, UC) {
//     MockDB db;
//     SearchPost Test_1(&db);
//     Message<ProjectData> msg = Test_1.makePostSearch(post.project_name);
//     EXPECT_EQ(ResponseStatus::ok, msg.status);
// }

// TEST(SearchPersonTest, UC) {
//     MockDB db;
//     std::string username = "cool_username";
//     SearchPerson Test_1(&db);
//     Message<UserData> msg = Test_1.makePersonSearch(username);
//     EXPECT_EQ(ResponseStatus::ok, msg.status);
// }

// TEST(MakeRequestToPostTest, UC) {
//     MockDB db;
//     EXPECT_CALL(db, InsertIntoRequestToPostTable(req)).Times(AtLeast(1)).WillOnce(Return(true));
//     MakeRequestToPost Test_1(&db);
//     EXPECT_EQ(Test_1.makeReqToPost(req), ResponseStatus::ok);
// }

// TEST(DeletePostTest, UC) {
//     MockDB db;
//     EXPECT_CALL(db, DeleteFromPostTable(post.project_name)).Times(AtLeast(1)).WillOnce(Return(true));
//     DeletePost Test_1(&db);
//     EXPECT_EQ(Test_1.delPostData(post.project_name), ResponseStatus::ok);
// }

// TEST(AnswerTheRequestTest, UC) {
//     MockDB db;
//     EXPECT_CALL(db, EditRequestToPostTable(req)).Times(AtLeast(1)).WillOnce(Return(true));
//     AnswerTheRequest Test_1(&db);
//     EXPECT_EQ(Test_1.getAnswer(false, req), ResponseStatus::ok);
// }

// TEST(ShowNotificationsTest, UC) {
//     MockDB db;
//     ShowNotifications Test_1(&db);
//     Message<NotificationData> msg = Test_1.showAllNotifications(1);
//     EXPECT_EQ(ResponseStatus::ok, msg.status);
// }

// TEST(CreatePostTest, UC) {
//     ockDB db;
//     EXPECT_CALL(db, InsertIntoPostTable(post)).Times(AtLeast(1)).WillOnce(Return(true));
//     CreatePost Test_1(&db);
//     EXPECT_EQ(Test_1.addPostToDB(post), ResponseStatus::ok);
// }

