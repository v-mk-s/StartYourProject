#include "server_usecases.hpp"
#include "database.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::AtLeast;
using ::testing::Return;



class MockDB: public MainDataBase {
 public:
    MOCK_METHOD(DBStatus, InsertIntoPostTable, (ProjectData &data), (override));
    MOCK_METHOD(DBStatus, InsertIntoUserTable, (UserData &data), (override));
    MOCK_METHOD(DBStatus, InsertIntoRequestToPostTable, (RequestToPostData &data), (override));

    MOCK_METHOD(DBStatus, DeleteFromPostTable, (std::string &project_name), (override));
    MOCK_METHOD(DBStatus, DeleteFromPersonTable, (std::string &username), (override));
    MOCK_METHOD(DBStatus, DeleteFromRequestToPostTable, (RequestToPostData &data), (override));

    MOCK_METHOD(DBStatus, EditUserInPersonTable, (UserData &data), (override));
    MOCK_METHOD(DBStatus, EditPostInPostTable, (ProjectData &data), (override));
    MOCK_METHOD(DBStatus, EditRequestToPostTable, (RequestToPostData &data), (override));

    MOCK_METHOD((Message<UserData, DBStatus>), FindIntoPersonByUsername, (std::string &username), (override));
    MOCK_METHOD((Message<ProjectData, DBStatus>), FindIntoPostTable, (std::string &project_name), (override));
    MOCK_METHOD((Message<std::vector<RequestToPostData>, DBStatus>),  FindRequestToPostTable, (std::string &username), (override));

    MOCK_METHOD(DBStatus, InsertToken, (std::string &username, std::string& token), (override));
    MOCK_METHOD((Message<std::string, DBStatus>), FindToken, (std::string &username), (override));
    MOCK_METHOD(DBStatus, DeleteToken, (std::string &username), (override));
};



TEST(LoginUCTest, GoodCase) {
    MockDB database;
    UserData test_data;
    test_data.username = "John_123-4";
    test_data.password = "qwerty1234";
    LoginUC usecase(&database);
    test_data.auth_token = usecase.generate_token(test_data.username + test_data.password);

    EXPECT_CALL(database, FindIntoPersonByUsername(test_data.username))
                .Times(1).WillOnce(Return(Message<UserData, DBStatus>(test_data)));

    EXPECT_CALL(database, InsertToken(test_data.username, test_data.auth_token))
                .Times(1).WillOnce(Return(DBStatus::ok));


    Message<UserData> msg = usecase.checkUser(test_data);
    EXPECT_EQ(ResponseStatus::ok, msg.status);
    EXPECT_TRUE(test_data.auth_token.length() != 0) << "auth_token dont generated";
}

TEST(LoginUCTest, WrongPassword) {
    MockDB database;
    UserData test_data;
    test_data.username = "John_123-4";
    test_data.password = "qwerty1234";
    LoginUC usecase(&database);
    test_data.auth_token = usecase.generate_token(test_data.username + test_data.password);

    EXPECT_CALL(database, FindIntoPersonByUsername(test_data.username))
                .Times(1).WillOnce(Return(Message<UserData, DBStatus>(test_data)));

    EXPECT_CALL(database, InsertToken(test_data.username, test_data.auth_token))
                .Times(1).WillOnce(Return(DBStatus::ok));


    Message<UserData> msg = usecase.checkUser(test_data);
    EXPECT_EQ(ResponseStatus::ok, msg.status);
    EXPECT_TRUE(test_data.auth_token.length() != 0) << "auth_token dont generated";
}

TEST(RegisterUCTest, GoodCase) {
    MockDB database;
    UserData test_data;
    test_data.username = "John_123-4";
    test_data.password = "qwerty1234";
    test_data.email = "email@mail.ru";
    EXPECT_CALL(database, FindIntoPersonByUsername(test_data.username))
                .Times(1).WillOnce(Return(DBStatus::not_found));

    EXPECT_CALL(database, InsertIntoUserTable(test_data)).
                Times(1).WillOnce(Return(DBStatus::ok));

    RegisterUC usecase(&database);

    EXPECT_EQ(ResponseStatus::ok, usecase.addUser(test_data));
}

TEST(EditProfileUCTest, GoodCase) {
    MockDB database;
    UserData test_data;
    test_data.name = "Jack";
    test_data.email = "email@mail.ru";
    test_data.username = "Abc";
    test_data.sur_name = "dfgh";
    test_data.user_description = "some text";
    test_data.password = "1234qwerty";

    EXPECT_CALL(database, CheckToken(test_data.username, test_data.auth_token))
                .Times(1).WillOnce(Return(false));

    EXPECT_CALL(database, EditUserInPersonTable(test_data))
                .Times(1).WillOnce(Return(DBStatus::ok));

    EditProfileUC usecase(&database);

    EXPECT_EQ(ResponseStatus::ok, usecase.editUserData(test_data));
}

TEST(DelUserProfileUCTest, GoodCase) {
    MockDB database;
    UserData test_data;
    test_data.username = "test123";
    test_data.auth_token = "23132";

    EXPECT_CALL(database, CheckToken(test_data.username, test_data.auth_token))
                .Times(1).WillOnce(Return(false));

    EXPECT_CALL(database, DeleteFromPersonTable(test_data.username))
                .Times(1).WillOnce(Return(DBStatus::ok));

    DelUserProfileUC usecase(&database);

    EXPECT_EQ(ResponseStatus::ok, usecase.delUserData(test_data));
}

TEST(GetUserProfileUCTest, GoodCase) {
    MockDB database;
    std::string test_username = "abcdefg";

    EXPECT_CALL(database, FindIntoPersonByUsername(test_username))
                .Times(1).WillOnce(Return(Message<UserData, DBStatus>(UserData())));

    GetUserProfileUC usecase(&database);

    EXPECT_EQ(ResponseStatus::ok, usecase.getUserData(test_username).status);
}


static ProjectData post;
// static RequestToPostData req = {1,2, "cool project", "I really want to join your team", RequestToPostData::Status::unknown};

TEST(EditPostTest, UC) {
    post.username = "admin";
    post.project_name = "project";
    post.team_name = "PyTorchki";
    post.post_tags.push_back("Python");
    post.teammates.push_back("Teammate");
    post.project_description = "cool project";

    std::string auth_token = "323324";
    MockDB db;

    EXPECT_CALL(db, CheckToken(post.username, auth_token))
                .Times(1).WillOnce(Return(false));

    EXPECT_CALL(db, EditPostInPostTable(post))
                .Times(1).WillOnce(Return(DBStatus::ok));

    EditPostUC Test_1(&db);
    EXPECT_EQ(Test_1.editPostToDB(post, auth_token), ResponseStatus::ok);
}

TEST(GetPostTest, UC) {
    MockDB db;

    EXPECT_CALL(db, FindIntoPostTable(post.project_name))
                .Times(1).WillOnce(Return(Message<ProjectData, DBStatus>(post)));

    GetPostUC Test_1(&db);
    Message<ProjectData> msg = Test_1.getPost(post.project_name);
    EXPECT_EQ(ResponseStatus::ok, msg.status);
}

// TEST(MakeRequestToPostTest, UC) {
//     MockDB db;
//     EXPECT_CALL(db, InsertIntoRequestToPostTable(req)).Times(AtLeast(1)).WillOnce(Return(true));
//     MakeRequestToPost Test_1(&db);
//     EXPECT_EQ(Test_1.makeReqToPost(req), ResponseStatus::ok);
// }

TEST(DeletePostTest, UC) {
    MockDB db;
    std::string auth_token = "323324";

    EXPECT_CALL(db, CheckToken(post.username, auth_token))
                .Times(1).WillOnce(Return(false));

    EXPECT_CALL(db, DeleteFromPostTable(post.project_name))
                .Times(AtLeast(1)).WillOnce(Return(DBStatus::ok));

    DeletePostUC Test_1(&db);
    EXPECT_EQ(Test_1.delPostData(post, auth_token), ResponseStatus::ok);
}

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

TEST(CreatePostTest, UC) {
    MockDB db;
    EXPECT_CALL(db, FindIntoPostTable(post.project_name))
                .Times(1).WillOnce(Return(Message<ProjectData, DBStatus>(DBStatus::not_found)));

    EXPECT_CALL(db, InsertIntoPostTable(post))
                .Times(1).WillOnce(Return(DBStatus::ok));

    CreatePostUC Test_1(&db);
    EXPECT_EQ(Test_1.addPostToDB(post, token), ResponseStatus::ok);
}

