#include "server_usecases.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::AtLeast;
using ::testing::Return;





class MockDB: public MainDataBase {
 public:
    MOCK_METHOD(bool, InsertIntoPersonTable, (RegisterData &data));
    MOCK_METHOD(bool, InsertIntoPostTable, (ProjectData &data));
    MOCK_METHOD(bool, InsertIntoRequestToPostTable, (RequestToPostData &data));

    MOCK_METHOD(bool, DeleteFromPostTable, (std::string &project_name));
    MOCK_METHOD(bool, DeleteFromPersonTable, (std::string &data));
    MOCK_METHOD(bool, DeleteFromRequestToPostTable, (RequestToPostData &data));

    MOCK_METHOD(bool, EditUserInPersonTable, (UserData &data));
    MOCK_METHOD(bool, EditPostInPostTable, (ProjectData &data));
    MOCK_METHOD(bool, EditRequestToPostTable, (RequestToPostData &data));

    MOCK_METHOD(bool, FindIntoPersonTable, (LoginData &data));
    MOCK_METHOD(bool, FindIntoPostTable, (std::string &project_name));
    MOCK_METHOD(NotificationData, FindRequestToPostTable, (int &user_id));

    MOCK_METHOD(UserData, getUserProfile, (std::string &username));
    MOCK_METHOD(ProjectData, getPost, (std::string &project_name));
    MOCK_METHOD(std::vector<ProjectData>, getMultiPost, (SearchData &data));
};



TEST(LoginUCTest, GoodCase) {
    MockDB database;
    LoginData test_data = {"John_123-4", "qwerty1234"};
    EXPECT_CALL(database, FindIntoPersonTable(test_data)).Times(1).WillOnce(Return(true));

    LoginUC usecase(&database);

    Message<std::string> msg = usecase.checkUser(test_data);
    EXPECT_EQ(ResponseStatus::ok, msg.status);
    EXPECT_TRUE(msg.data.length() != 0) << "Message: " << msg.data; 
}


TEST(RegisterUCTest, GoodCase) {
    MockDB database;
    RegisterData test_data = {"Jack", "1q2w3e4r5t6y", "email@mail.ru"};
    EXPECT_CALL(database, InsertIntoPersonTable(test_data)).Times(1).WillOnce(Return(true));

    RegisterUC usecase(&database);

    Message<std::string> msg = usecase.addUser(test_data);
    EXPECT_EQ(ResponseStatus::ok, msg.status);
    EXPECT_EQ(msg.data.length(), 0) << "Message: " << msg.data;
}

TEST(EditProfileUCTest, GoodCase) {
    MockDB database;
    UserData test_data = {"Jack", "email@mail.ru", "Abc", "dfgh", "some text", "1234qwerty"};
    EXPECT_CALL(database, EditUserInPersonTable(test_data)).Times(1).WillOnce(Return(true));

    EditProfileUC usecase(&database);

    Message<std::string> msg = usecase.editUserData(test_data);
    EXPECT_EQ(ResponseStatus::ok, msg.status);
    EXPECT_EQ(msg.data.length(), 0) << "Message: " << msg.data;
}

TEST(DelUserProfileUCTest, GoodCase) {
    MockDB database;
    std::string test_username = "abcdefg";
    EXPECT_CALL(database, DeleteFromPersonTable(test_username)).Times(1).WillOnce(Return(true));

    DelUserProfileUC usecase(&database);

    Message<std::string> msg = usecase.delUserData(test_username);
    EXPECT_EQ(ResponseStatus::ok, msg.status);
    EXPECT_EQ(msg.data.length(), 0) << "Message: " << msg.data;
}

TEST(GetUserProfileUCTest, GoodCase) {
    MockDB database;
    std::string test_username = "abcdefg";
    EXPECT_CALL(database, getUserProfile(test_username)).Times(1);

    GetUserProfileUC usecase(&database);

    Message<UserData> msg = usecase.getUserData(test_username);
    EXPECT_EQ(ResponseStatus::ok, msg.status);
}


ProjectData post = {"project", "PyTorchki", {"Python"}, {"Teammate"}, "cool project", 0.99, "i want you"};
RequestToPostData req = {1, 2, "I really want to join your team", RequestToPostData::Status::unknown};

TEST(EditPostTest, UC) {
    MockDB db;
    EXPECT_CALL(db, EditPostInPostTable(post)).Times(AtLeast(1)).WillOnce(Return(true));
    EditPost Test_1(&db);
    EXPECT_EQ(Test_1.editPostToDB(post), ResponseStatus::ok);
}

TEST(SearchPostTest, UC) {
    MockDB db;
    SearchPost Test_1(&db);
    Message<ProjectData> msg = Test_1.makePostSearch(post.project_name);
    EXPECT_EQ(ResponseStatus::ok, msg.status);
}

TEST(SearchPersonTest, UC) {
    MockDB db;
    std::string username = "cool_username";
    SearchPerson Test_1(&db);
    Message<UserData> msg = Test_1.makePersonSearch(username);
    EXPECT_EQ(ResponseStatus::ok, msg.status);
}

TEST(MakeRequestToPostTest, UC) {
    MockDB db;
    EXPECT_CALL(db, InsertIntoRequestToPostTable(req)).Times(AtLeast(1)).WillOnce(Return(true));
    MakeRequestToPost Test_1(&db);
    EXPECT_EQ(Test_1.makeReqToPost(req), ResponseStatus::ok);
}

TEST(DeletePostTest, UC) {
    MockDB db;
    EXPECT_CALL(db, DeleteFromPostTable(post.project_name)).Times(AtLeast(1)).WillOnce(Return(true));
    DeletePost Test_1(&db);
    EXPECT_EQ(Test_1.delPostData(post.project_name), ResponseStatus::ok);
}

TEST(AnswerTheRequestTest, UC) {
    MockDB db;
    EXPECT_CALL(db, EditRequestToPostTable(req)).Times(AtLeast(1)).WillOnce(Return(true));
    AnswerTheRequest Test_1(&db);
    EXPECT_EQ(Test_1.getAnswer(false, req), ResponseStatus::ok);
}

TEST(ShowNotificationsTest, UC) {
    MockDB db;
    ShowNotifications Test_1(&db);
    Message<NotificationData> msg = Test_1.showAllNotifications(1);
    EXPECT_EQ(ResponseStatus::ok, msg.status);
}

TEST(CreatePostTest, UC) {
    MockDB db;
    EXPECT_CALL(db, InsertIntoPostTable(post)).Times(AtLeast(1)).WillOnce(Return(true));
    CreatePost Test_1(&db);
    EXPECT_EQ(Test_1.addPostToDB(post), ResponseStatus::ok);
}

