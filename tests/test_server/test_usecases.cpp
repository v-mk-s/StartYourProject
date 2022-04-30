#include "handlers.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>


class MockDB: public MainDataBase {
 public:
    MOCK_METHOD(bool, InsertIntoTable, ());
    MOCK_METHOD(bool, DeleteFromTable, ());
    MOCK_METHOD(bool, FindIntoTable, ());
    MOCK_METHOD(bool, InsertIntoPostTable, ());
    MOCK_METHOD(bool, InsertIntoRequestToPostTable, ());
    MOCK_METHOD(bool, DeleteFromPostTable, ());
    MOCK_METHOD(bool, DeleteFromPersonTable, ());
    MOCK_METHOD(bool, DeleteFromRequestToPostTable, ());
};


TEST(LoginUCTest, GoodCase) {
    MockDB database;
    EXPECT_CALL(database, FindIntoTable()).Times(testing::AtLeast(1));

    LoginData test_data = {"John", "qwerty"};
    LoginUC usecase(&database);

    EXPECT_EQ(ErrorStatus::no_error, usecase.checkUserInDB(test_data)); 
}

TEST(LoginUCTest, WrongName) {
    MockDB database;
    EXPECT_CALL(database, FindIntoTable()).Times(0);

    LoginData test_data = {"", "qwerty"};
    LoginUC usecase(&database);

    EXPECT_EQ(ErrorStatus::wrong_data, usecase.checkUserInDB(test_data)); 
}

TEST(RegisterUCTest, GoodCase) {
    MockDB database;
    EXPECT_CALL(database, InsertIntoTable()).Times(testing::AtLeast(1));

    RegisterData test_data = {"Jack", "1234", "email@mail.ru"};
    RegisterUC usecase(&database);

    EXPECT_EQ(ErrorStatus::no_error, usecase.addUserToDB(test_data));
}

TEST(RegisterUCTest, WrongEmail) {
    MockDB database;
    EXPECT_CALL(database, InsertIntoTable()).Times(0);

    RegisterData test_data = {"Jack", "1234", "email.ru@sldfj"};
    RegisterUC usecase(&database);

    EXPECT_EQ(ErrorStatus::wrong_data, usecase.addUserToDB(test_data));
}

TEST(EditProfileUCTest, GoodCase) {
    MockDB database;
    EXPECT_CALL(database, InsertIntoTable()).Times(testing::AtLeast(1));

    UserData test_data = {"Jack", "email@mail.ru", "Abc", "dfgh", "some text", "qwerty"};
    EditProfileUC usecase(&database);

    EXPECT_EQ(ErrorStatus::no_error, usecase.editUserData(test_data));
}

TEST(DelUserProfileUCTest, GoodCase) {
    MockDB database;
    EXPECT_CALL(database, DeleteFromTable()).Times(0);

    std::string test_username = "abcdefg";
    DelUserProfileUC usecase(&database);

    EXPECT_EQ(ErrorStatus::no_error, usecase.delUserData(test_username));
}

TEST(GetUserProfileUCTest, GoodCase) {
    MockDB database;
    EXPECT_CALL(database, FindIntoTable()).Times(0);

    std::string test_username = "abcdefg";
    GetUserProfileUC usecase(&database);

    Message<UserData> test_message = {ErrorStatus::wrong_data, UserData()};

    EXPECT_EQ(test_message.type, usecase.getUserData(test_username).type);
}


PostData post={1,"проект", "классный проект","Стартап", "PyTorchki"};
RequestToPostData req={1,2, "Очень хочу к вам в команду"};


TEST(EditPostTest, UC) {
    MockDB db;
    EXPECT_CALL(db, InsertIntoPostTable()).Times(testing::AtLeast(1));
    EXPECT_CALL(db, DeleteFromPostTable()).Times(testing::AtLeast(1));
    EditPost Test_1(&db);
    EXPECT_EQ(Test_1.editPostToDB(post), ErrorStatus::no_error);
}

TEST(SearchPostTest, UC) {
    MockDB db;
    SearchPost Test_1(&db);
    EXPECT_EQ(Test_1.makePostSearch(post), ErrorStatus::no_error);
}

TEST(SearchPersonTest, UC) {
    MockDB db;
    SearchPerson Test_1(&db);
    EXPECT_EQ(Test_1.makePersonSearch("cool_username"), ErrorStatus::no_error);
}

TEST(MakeRequestToPostTest, UC) {
    MockDB db;
    EXPECT_CALL(db, InsertIntoRequestToPostTable()).Times(testing::AtLeast(1));
    MakeRequestToPost Test_1(&db);
    EXPECT_EQ(Test_1.makeReqToPost(req), ErrorStatus::no_error);
}

TEST(DeletePostTest, UC) {
    MockDB db;
    EXPECT_CALL(db, DeleteFromPostTable()).Times(testing::AtLeast(1));
    DeletePost Test_1(&db);
    EXPECT_EQ(Test_1.delPostData(1), ErrorStatus::no_error);
}

TEST(AnswerTheRequestTest, UC) {
    MockDB db;
    AnswerTheRequest Test_1(&db);
    EXPECT_EQ(Test_1.getAnswer(false, req), ErrorStatus::no_error);
}

TEST(ShowNotificationsTest, UC) {
    MockDB db;
    ShowNotifications Test_1(&db);
    EXPECT_EQ(Test_1.showAllNotifications(1), ErrorStatus::no_error);
}

TEST(CreatePostTest, UC) {
    MockDB db;
    EXPECT_CALL(db, InsertIntoPostTable()).Times(testing::AtLeast(1));
    CreatePost Test_1(&db);
    EXPECT_EQ(Test_1.addPostToDB(post), ErrorStatus::no_error);
}
