#include "gtest/gtest.h"
#include "utils.h"
#include "../../server_us/server_usecases.h"

post post={1,"проект", "классный проект","Стартап", "PyTorchki"};
RequestToPostData req={1,2, "Очень хочу к вам в команду"};

class MockDB: public DataBase {
 public:
    MOCK_METHOD(bool, InsertIntoPostTable, ());
    MOCK_METHOD(bool, InsertIntoRequestToPostTable, ());
    MOCK_METHOD(bool, DeleteFromPostTable, ());
    MOCK_METHOD(bool, DeleteFromPersonTable, ());
    MOCK_METHOD(bool, DeleteFromRequestToPostTable, ());
};


TEST(EDITPOST, UC) {
MockDB db;
EXPECT_CALL(db, InsertIntoPostTable()).Times(testing::AtLeast(1));
EXPECT_CALL(db, DeleteFromPostTable()).Times(testing::AtLeast(1));
EditPost Test_1(db);
EXPECT_EQ(Test_1.editPostToDB(post), noError)
}

TEST(SearchPost, UC) {
SearchPost Test_1(db);
EXPECT_EQ(Test_1.makePostSearch(post), noError)

}

TEST(SearchPerson, UC) {
MockDB db;
SearchPerson Test_1(db);
EXPECT_EQ(Test_1.makePersonSearch("cool_username"), noError)
}

TEST(MakeRequestToPost, UC) {
MockDB db;
EXPECT_CALL(db, InsertIntoRequestToPostTable()).Times(testing::AtLeast(1));
MakeRequestToPost Test_1(db);
EXPECT_EQ(Test_1.makeReqToPost(req), noError)
}
TEST(DeletePost, UC) {
MockDB db;
EXPECT_CALL(db, DeleteFromPostTable()).Times(testing::AtLeast(1));
DeletePost Test_1(db);
EXPECT_EQ(Test_1.delPostData(1), noError)
}
TEST(AnswerTheRequest, UC) {
MockDB db;
AnswerTheRequest Test_1(db);
EXPECT_EQ(Test_1.getAnswer(False, req), noError)
}

TEST(ShowNotifications, UC) {
MockDB db;
ShowNotifications Test_1(db);
EXPECT_EQ(Test_1.showAllNotifications(1), noError)
}

TEST(CreatePost, UC) {
MockDB db;
EXPECT_CALL(db, InsertIntoPostTable()).Times(testing::AtLeast(1));
CreatePost Test_1(db);
EXPECT_EQ(Test_1.addPostToDB(post), noError)
}