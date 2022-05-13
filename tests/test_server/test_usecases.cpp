#include "server_usecases.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::AtLeast;
using ::testing::Return;


class MockDB: public MainDataBase {
 public:
    MOCK_METHOD(bool, InsertIntoPersonTable, (RegisterData &data));
    MOCK_METHOD(bool, InsertIntoPostTable, ());
    MOCK_METHOD(bool, InsertIntoRequestToPostTable, ());

    MOCK_METHOD(bool, DeleteFromPostTable, ());
    MOCK_METHOD(bool, DeleteFromPersonTable, (std::string &data));
    MOCK_METHOD(bool, DeleteFromRequestToPostTable, (RequestToPostData &data));

    MOCK_METHOD(bool, EditUserInPersonTable, (UserData &data));

    MOCK_METHOD(bool, FindIntoPersonTable, (LoginData &data));

    MOCK_METHOD(UserData, getUserProfile, (std::string &username));
};



TEST(LoginUCTest, GoodCase) {
    MockDB database;
    LoginData test_data = {"John_123-4", "qwerty1234"};
    EXPECT_CALL(database, FindIntoPersonTable(test_data)).Times(1).WillOnce(Return(true));

    LoginUC usecase(&database);

    Message<std::string> msg = usecase.checkUser(test_data);
    EXPECT_EQ(ErrorStatus::ok, msg.status);
    EXPECT_TRUE(msg.data.length() != 0) << "Message: " << msg.data; 
}

TEST(LoginUCTest, WrongName) {
    MockDB database;
    LoginData test_data = {"User.1/@?)", "1234qwerty"};
    LoginUC usecase(&database);

    EXPECT_CALL(database, FindIntoPersonTable(test_data)).Times(0);

    Message<std::string> msg = usecase.checkUser(test_data);
    EXPECT_EQ(ErrorStatus::wrong_data, msg.status); 
    EXPECT_EQ(WRONG_NAME, msg.data);
}

TEST(LoginUCTest, EmptyName) {
    MockDB database;
    LoginData test_data = {"", "1234qwerty"};
    EXPECT_CALL(database, FindIntoPersonTable(test_data)).Times(0);

    LoginUC usecase(&database);

    Message<std::string> msg = usecase.checkUser(test_data);
    EXPECT_EQ(ErrorStatus::wrong_data, msg.status); 
    EXPECT_EQ(WRONG_NAME, msg.data);
}

TEST(LoginUCTest, EmptyPassword) {
    MockDB database;
    LoginData test_data = {"Password", ""};
    EXPECT_CALL(database, FindIntoPersonTable(test_data)).Times(0);

    LoginUC usecase(&database);

    Message<std::string> msg = usecase.checkUser(test_data);
    EXPECT_EQ(ErrorStatus::wrong_data, msg.status); 
    EXPECT_EQ(WRONG_PASSWORD, msg.data);
}

TEST(RegisterUCTest, GoodCase) {
    MockDB database;
    RegisterData test_data = {"Jack", "1q2w3e4r5t6y", "email@mail.ru"};
    EXPECT_CALL(database, InsertIntoPersonTable(test_data)).Times(1).WillOnce(Return(true));

    RegisterUC usecase(&database);

    Message<std::string> msg = usecase.addUser(test_data);
    EXPECT_EQ(ErrorStatus::ok, msg.status);
    EXPECT_EQ(msg.data.length(), 0) << "Message: " << msg.data;
}

TEST(RegisterUCTest, WrongEmail) {
    MockDB database;
    RegisterData test_data = {"Jack", "1q2w3e4r5t6y", "email.ru@sldfj"};
    EXPECT_CALL(database, InsertIntoPersonTable(test_data)).Times(0);

    RegisterUC usecase(&database);

    Message<std::string> msg = usecase.addUser(test_data);
    EXPECT_EQ(ErrorStatus::wrong_data, msg.status);
    EXPECT_EQ(WRONG_EMAIL, msg.data);
}

TEST(EditProfileUCTest, GoodCase) {
    MockDB database;
    UserData test_data = {"Jack", "email@mail.ru", "Abc", "dfgh", "some text", "1234qwerty"};
    EXPECT_CALL(database, EditUserInPersonTable(test_data)).Times(1).WillOnce(Return(true));

    EditProfileUC usecase(&database);

    Message<std::string> msg = usecase.editUserData(test_data);
    EXPECT_EQ(ErrorStatus::ok, msg.status);
    EXPECT_EQ(msg.data.length(), 0) << "Message: " << msg.data;
}

TEST(DelUserProfileUCTest, GoodCase) {
    MockDB database;
    std::string test_username = "abcdefg";
    EXPECT_CALL(database, DeleteFromPersonTable(test_username)).Times(1).WillOnce(Return(true));

    DelUserProfileUC usecase(&database);

    Message<std::string> msg = usecase.delUserData(test_username);
    EXPECT_EQ(ErrorStatus::ok, msg.status);
    EXPECT_EQ(msg.data.length(), 0) << "Message: " << msg.data;
}

TEST(GetUserProfileUCTest, GoodCase) {
    MockDB database;
    std::string test_username = "abcdefg";
    EXPECT_CALL(database, getUserProfile(test_username)).Times(1);

    GetUserProfileUC usecase(&database);

    Message<UserData> msg = usecase.getUserData(test_username);
    EXPECT_EQ(ErrorStatus::ok, msg.status);
}


PostData post={1,"проект", "классный проект","Стартап", "PyTorchki"};
RequestToPostData req={1,2, "Очень хочу к вам в команду"};


TEST(EditPostTest, UC) {
    MockDB db;
    EXPECT_CALL(db, InsertIntoPostTable()).Times(AtLeast(1));
    EXPECT_CALL(db, DeleteFromPostTable()).Times(AtLeast(1));
    EditPost Test_1(&db);
    EXPECT_EQ(Test_1.editPostToDB(post), ErrorStatus::ok);
}

TEST(SearchPostTest, UC) {
    MockDB db;
    SearchPost Test_1(&db);
    EXPECT_EQ(Test_1.makePostSearch(post), ErrorStatus::ok);
}

TEST(SearchPersonTest, UC) {
    MockDB db;
    SearchPerson Test_1(&db);
    EXPECT_EQ(Test_1.makePersonSearch("cool_username"), ErrorStatus::ok);
}

TEST(MakeRequestToPostTest, UC) {
    MockDB db;
    EXPECT_CALL(db, InsertIntoRequestToPostTable()).Times(AtLeast(1));
    MakeRequestToPost Test_1(&db);
    EXPECT_EQ(Test_1.makeReqToPost(req), ErrorStatus::ok);
}

TEST(DeletePostTest, UC) {
    MockDB db;
    EXPECT_CALL(db, DeleteFromPostTable()).Times(AtLeast(1));
    DeletePost Test_1(&db);
    EXPECT_EQ(Test_1.delPostData(1), ErrorStatus::ok);
}

TEST(AnswerTheRequestTest, UC) {
    MockDB db;
    AnswerTheRequest Test_1(&db);
    EXPECT_EQ(Test_1.getAnswer(false, req), ErrorStatus::ok);
}

TEST(ShowNotificationsTest, UC) {
    MockDB db;
    ShowNotifications Test_1(&db);
    EXPECT_EQ(Test_1.showAllNotifications(1), ErrorStatus::ok);
}

TEST(CreatePostTest, UC) {
    MockDB db;
    EXPECT_CALL(db, InsertIntoPostTable()).Times(AtLeast(1));
    CreatePost Test_1(&db);
    EXPECT_EQ(Test_1.addPostToDB(post), ErrorStatus::ok);
}
