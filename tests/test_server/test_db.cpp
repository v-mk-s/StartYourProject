#include "gtest/gtest.h"
#include "utils.h"
#include "../../database/database.h"



TEST(CONNECTION, CORRECT_CONNECTION) {
    DataBase db();
    EXPECT_NO_THROW(db.connectToDataBase());
}

TEST(FUNC, UNCORRECT_FUNCTION) {
    DataBase db();
    const QvariantList data=5;
    EXPECT_FALSE(db.InsertIntoPostTable(&data));
    EXPECT_FALSE(db.InsertIntoPersonTable(&data));
    EXPECT_FALSE(db.InsertIntoRequestToPostTable(&data));
    EXPECT_FALSE(db.DeleteFromPostTable(&data));
    EXPECT_FALSE(db.DeleteFromPersonTable(&data));
    EXPECT_FALSE(db.DeleteFromRequestToPostTable(&data));
}
