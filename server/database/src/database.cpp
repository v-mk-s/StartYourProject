#include "database.hpp"


MainDataBase::MainDataBase(): 
        sqlconn(mysqlx::Session(HOST, PORT, DB_USER, DB_PASSWORD)),
        db(sqlconn.getSchema("SYP_DB")),
        user_data_table(db.getTable("user_data")),
        project_data_table(db.getTable("project_data")),
        token_data_table(db.getTable("token_data")),
        notification_data_table(db.getTable("notification_data")) {}



MainDataBase::~MainDataBase() {
    sqlconn.close();
}



DBStatus MainDataBase::DeleteFromPersonTable(std::string &username) {

    user_data_table.remove()
    .where("id=:param")
    // .bind("param",id)
    .execute();
    return DBStatus::ok;
}
DBStatus MainDataBase::DeleteToken(std::string& username){
    token_data_table.remove()
    .where("username=:param")
    .bind("param",username)
    .execute();
    return DBStatus::ok;
}

DBStatus MainDataBase::DeleteFromPostTable(std::string& username) {
    // MySQLQuery * que = new MySQLQuery(sqlconn, "DELETE from projectdata where project_id=?");
    // que->setInt(1,id);
    // return que->ExecuteUpdate();

    return DBStatus::ok;
}

DBStatus MainDataBase::DelFromTableNotifications(RequestToPostData& data) {
    // MySQLQuery * que = new MySQLQuery(sqlconn, "DELETE from requesttopost where user_id=? and project_id=?");
    // que->setInt(1,data.user_id);
    // que->setInt(2,data.post_id);
    // return que->ExecuteUpdate();
    project_data_table.remove()
    .where("project_id=:param")
    // .bind("param",data.user_id)
    .execute();
    return DBStatus::ok;

}
DBStatus MainDataBase::DeleteFromRequestToPostTable(RequestToPostData &data) {
    // MySQLQuery * que = new MySQLQuery(sqlconn, "DELETE from requesttopost where user_id=? and project_id=?");

    return DBStatus::ok;
}

Message<std::vector<RequestToPostData>, DBStatus> MainDataBase::FindRequestToPostTable(std::string &username) {
    //выводим оповещения-ответы на пост юзера, либо ответы на его отклики
    // MySQLQuery * selectQuery = new MySQLQuery(sqlconn, "select r.user_id, \
    // r.project_id, p.project_name, r.motivation_words, r.status from requesttopost as r \
    // inner join projectdata as p on r.project_id=p.project_id where r.user_id=? and r.status<>3 or p.user_id=?")


    
    // selectQuery->setInt(1,user_id);
    // selectQuery->setInt(2,user_id);
    // selectQuery->ExecuteQuery();
    // std::vector<RequestToPostData> data;

    // for (unsigned int i=1; i<=selectQuery->GetResultRowCount(); i++)
    // {
    //     RequestToPostData temp;

    //     temp.user_id=selectQuery->getInt(i,1);
    //     temp.post_id=selectQuery->getInt(i,2);
    //     temp.project_name=selectQuery->getString(i,3);
    //     temp.motivation_words=selectQuery->getString(i,4);

    //     temp.status=static_cast<Status>(selectQuery->getInt(i,5));
    //     data.push_back(temp);
    // }

    return std::vector<RequestToPostData>();
}

Message<UserData, DBStatus> MainDataBase::FindIntoPersonByUsername(std::string &username) {
    mysqlx::RowResult res = user_data_table.select("id", "user_name", "email", "name", "sur_name", "user_discription", "password")
    .where("user_name = :param")
    .orderBy("name")
    .bind("param",username)
    .execute();
    
    UserData data;
    mysqlx::Row row = res.fetchOne();

    // data.id = row[0];
    data.username = std::string(row[1]);
    data.email = std::string(row[2]);
    data.name = std::string(row[3]);
    data.sur_name = std::string(row[4]);
    data.user_discription = std::string(row[5]);
    data.password = std::string(row[6]);
    return Message<UserData, DBStatus>(data);
}

// UserData MainDataBase::FindIntoPersonByID(int id) {
//     mysqlx::RowResult res = user_data_table.select("id", "user_name", "email", "name", "sur_name", "user_discription", "password")
//     .where("id = :param")
//     .orderBy("name")
//     .bind("param",id)
//     .execute();
    
//     UserData data;
//     mysqlx::Row row = res.fetchOne();
    
//     data.id = row[0];
//     data.username = std::string(row[1]);
//     data.email = std::string(row[2]);
//     data.name = std::string(row[3]);
//     data.sur_name = std::string(row[4]);
//     data.user_discription = std::string(row[5]);
//     data.password = std::string(row[6]);
//     return data;
// }

// ProjectData MainDataBase::SelectPostByID(int &id) {
//     mysqlx::RowResult res = project_data_table.select("id", "userid", "project_name", "team_name", "post_tag", "teammates", "project_description", "diversity")
//     .where("id= :param")
//     .orderBy("project_name")
//     .bind("param",id)
//     .execute();

//     ProjectData data;
//     mysqlx::Row row = res.fetchOne();

//     data.projectid = row[0];
//     data.userid = row[1];
//     data.project_name = std::string(row[2]);
//     data.team_name = std::string(row[3]);
//     data.post_tags.push_back(std::string(row[4]));
//     data.teammates.push_back(std::string(row[5]));
//     data.project_description = std::string(row[6]);
//     data.diversity = row[7];
    
//     return data;
// }

// ProjectData MainDataBase::SelectPostByProjectname(std::string &project_name) {
//     mysqlx::RowResult res = project_data_table.select("id", "userid", "project_name", "team_name", "post_tag", "teammates", "project_description", "diversity")
//     .where("project_name= :param")
//     .orderBy("project_name")
//     .bind("param",project_name)
//     .execute();

//     ProjectData data;
//     mysqlx::Row row = res.fetchOne();
    
//     data.projectid = row[0];
//     data.userid = row[1];
//     data.project_name = std::string(row[2]);
//     data.team_name = std::string(row[3]);
//     data.post_tags.push_back(std::string(row[4]));
//     data.teammates.push_back(std::string(row[5]));
//     data.project_description = std::string(row[6]);
//     data.diversity = row[7];

//     return data;
// }

DBStatus MainDataBase::InsertIntoPostTable(ProjectData &data) {
    project_data_table.insert("project_name","team_name","post_tags","teammates","project_description","diversity")
    .values(1, data.project_name)
    .values(2, data.team_name)
    .values(3, data.post_tags[0])
    .values(4, data.teammates[0])
    .values(5, data.project_description)
    .values(6, data.diversity)
    .execute();

    return DBStatus::ok;
}

DBStatus MainDataBase::InsertIntoUserTable(UserData &data) {
    user_data_table.insert("email", "user_name","password")
    .values(1,data.email)
    .values(2, data.username)
    .values(3, data.password)
    .execute();

    return DBStatus::ok;
}



DBStatus MainDataBase::InsertIntoRequestToPostTable(RequestToPostData &data) {
    notification_data_table.insert("user_id", "post_id", "motivation_words", "status")
    // .values(1,data.user_id)
    // .values(2, data.post_id)
    .values(3, data.motivation_words)
    .values(4, 3)
    .execute();

    return DBStatus::ok;
}


DBStatus MainDataBase::InsertToken(std::string &username, std::string& token) {
    token_data_table.insert("user_name","token")
    .values(1,username)
    .values(2,token)
    .execute();
}

//updatам дописать sql-запросы

DBStatus MainDataBase::EditUserInPersonTable(UserData &data) {
    user_data_table.update()
    .set("user_name", mysqlx::expr(":param1"))
    .set("email", mysqlx::expr(":param2"))
    .set("name", mysqlx::expr(":param3"))
    .set("sur_name", mysqlx::expr(":param4"))
    .set("user_description", mysqlx::expr(":param5"))
    .set("password", mysqlx::expr(":param6"))
    .where("id=:param7")
    .bind("param1", data.username)
    .bind("param2", data.email)
    .bind("param3", data.name)
    .bind("param4", data.sur_name)
    .bind("param5", data.user_discription)
    .bind("param6", data.password)
    // .bind("param7", data.id)
    .execute();

    return DBStatus::ok;
}

DBStatus MainDataBase::EditPostInPostTable(ProjectData &data) {
    project_data_table.update()
    .set("project_name", mysqlx::expr(":param1"))
    .set("team_name", mysqlx::expr(":param2"))
    .set("post_tags", mysqlx::expr(":param3"))
    .set("teammates", mysqlx::expr(":param4"))
    .set("project_description", mysqlx::expr(":param5"))
    .set("diversity", mysqlx::expr(":param6"))
    .where("id_project=:param7")
    .bind("param1", data.project_name)
    .bind("param2", data.team_name)
    .bind("param3", data.post_tags[0])
    .bind("param4", data.teammates[0])
    .bind("param5", data.project_description)
    .bind("param6", data.diversity)
    // .bind("param7", data.projectid)
    .execute();
    return DBStatus::ok;
}


DBStatus MainDataBase::EditRequestToPostTable(RequestToPostData &data){
    // MySQLQuery * updateQuery = new MySQLQuery(sqlconn, "update requesttopost set status=? where post_id=?, user_id=?")
    // updateQuery->setInt(1,static_cast<Status>(data.status));
    // updateQuery->setInt(2,data.user_id);
    // updateQuery->setInt(3,data.post_id);

    // updateQuery->ExecuteUpdate();

    return DBStatus::ok;
}


// DBStatus MainDataBase::IsUnique(std::string &username) {
//     mysqlx::RowResult res = user_data_table.select("username")
//     .where("username=:param")
//     .bind("param", username)
//     .execute();
//     return res.();
// }

bool MainDataBase::CheckToken(std::string &username, std::string& token) {
    mysqlx::SqlResult res = sqlconn.sql("select * from token_data where  username=:param")
    .bind("param", username)
    .execute();
    return res.hasData();
}

Message<ProjectData, DBStatus> MainDataBase::FindIntoPostTable(std::string &project_name) {
    return DBStatus::ok;
}
