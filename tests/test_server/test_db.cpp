#include "utils.hpp"
#include <gtest/gtest.h>
#include "database.hpp"



TEST(CONNECTION, CORRECT_CONNECTION) {
    MainDataBase db;
    EXPECT_NO_THROW(db.connectToDataBase());
}

TEST(FUNC, UNCORRECT_FUNCTION) {
    MainDataBase db;
    // const QvariantList data=5;
    PostData post_data;
    UserData user_data;
    RequestToPostData req_data;

    EXPECT_FALSE(db.InsertIntoPostTable(post_data));
    EXPECT_FALSE(db.InsertIntoPersonTable(user_data));
    EXPECT_FALSE(db.InsertIntoRequestToPostTable(req_data));
    EXPECT_FALSE(db.DeleteFromPostTable(post_data));
    EXPECT_FALSE(db.DeleteFromPersonTable(user_data));
    EXPECT_FALSE(db.DeleteFromRequestToPostTable(req_data));
}
