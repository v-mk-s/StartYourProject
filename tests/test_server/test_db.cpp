#include "server_utils.hpp"
#include <gtest/gtest.h>
#include "database.hpp"



//  TEST(CONNECTION, CORRECT_CONNECTION) {
//      MainDataBase db;
//     EXPECT_NO_THROW();
//  }

 TEST(FUNC, UNCORRECT_FUNCTION) {
     MainDataBase db;
//     // const QvariantList data=5;
     ProjectData post_data;
//     UserData user_data;
//     RegisterData reg_data;
//     RequestToPostData req_data;
//     std::string username;
       
<<<<<<< HEAD
     EXPECT_TRUE(ok = db.InsertIntoPostTable(post_data));
=======
     EXPECT_TRUE(DBStatus::ok == db.InsertIntoPostTable(post_data));
>>>>>>> b7051dbb4a25d9a055884002a8e46ed2e27902ba
//     EXPECT_TRUE(db.InsertIntoPersonTable(reg_data));
//     EXPECT_TRUE(db.InsertIntoRequestToPostTable(req_data));
//     EXPECT_TRUE(db.DeleteFromPostTable(post_data.project_name));
//     EXPECT_TRUE(db.DeleteFromPersonTable(username));
//     EXPECT_TRUE(db.DeleteFromRequestToPostTable(req_data));
 }
