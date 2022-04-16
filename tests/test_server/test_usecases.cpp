#include "handlers.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>


class MockDB: public DataBase {
 public:
    MOCK_METHOD(bool, InsertIntoTable, ());
    MOCK_METHOD(bool, DeleteFromTable, ());
    MOCK_METHOD(bool, FindIntoTable, ());
};


TEST(LoginUCTest, GoodCase) {
    MockDB database;
    EXPECT_CALL(database, FindIntoTable()).Times(AtLeast(1));

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
    EXPECT_CALL(database, InsertIntoTable()).Times(AtLeast(1));

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
    EXPECT_CALL(database, InsertIntoTable()).Times(AtLeast(1));

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

    Message<UserData> test_message;
    test_message.type = ErrorStatus::wrong_data;

    EXPECT_EQ(test_message.type, usecase.getUserData(test_username).type);
}
