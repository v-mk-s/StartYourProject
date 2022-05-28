#include "idatabase.hpp"
#include <mysql-cppconn-8/mysqlx/xdevapi.h>


MainDataBase::MainDataBase(){
    sqlconn("127.0.0.1", 3306, "root", "password");
    db= sess.getSchema("SYP_DB");
    user_data_table = db.getTable("user_data");
    project_data_table = db.getTable("project_data");
    token_data_table = db.getTable("token_data");
    notification_data_table = db.getTable("notification_data");
}



MainDataBase::~MainDataBase(){
    sqlconn.Disconnect();
}



bool MainDataBase::DeleteFromPersonTable(std::string &username){

    user_data_table.delete()
    .where("username=:param")
    .bind("param",username)
    .execute();
    return true;
}
bool MainDataBase::DeleteToken(std::string &username){
    token_data_table.delete()
    .where("username=:param")
    .bind("param",username)
    .execute();
    return true;
}

bool MainDataBase::DeleteFromPostTable(int &id){
    project_data_table.delete()
    .where("project_id=:param")
    .bind("param",id)
    .execute();
    return true;

}
bool MainDataBase::DeleteFromRequestToPostTable(RequestToPostData &data){
    // MySQLQuery * que = new MySQLQuery(sqlconn, "DELETE from requesttopost where user_id=? and project_id=?");

    return true;
}

std::vector<RequestToPostData> MainDataBase::FindRequestToPostTable(int &user_id)
{
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

UserData MainDataBase::FindIntoPersonByUsername(std::string &username){
    RowResult res = user_data_table.select("id", "username", "email", "name", "sur_name", "user_discription", "password")
    .where("username = :param")
    .orderBy("name")
    .bind("param",username)
    .execute();
    
    UserData data;
    data.id=res[0];
    data.username=res[1];
    data.email=res[2];
    data.name=res[3];
    data.sur_name=res[4];
    data.user_discription=res[5];
    data.password=res[6];
    return data;
}
UserData MainDataBase::FindIntoPersonByID(int &id){
    RowResult res = user_data_table.select("id", "username", "email", "name", "sur_name", "user_discription", "password")
    .where("id = :param")
    .orderBy("name")
    .bind("param",id)
    .execute();
    
    UserData data;
    data.id=res[0];
    data.username=res[1];
    data.email=res[2];
    data.name=res[3];
    data.sur_name=res[4];
    data.user_discription=res[5];
    data.password=res[6];
    return data;
}

ProjectData MainDataBase::SelectPostByID(int &id)
{
    RowResult res = project_data_table.select("id", "userid", "project_name", "team_name", "post_tag", "teammates", "project_description", "diversity")
   .where("id= :param")
   .orderBy("project_name")
   .bind("param",id)
   .execute();

   ProjectData data;
   data.id=res[0];
   data.userid=res[1];
   data.project_name=res[2];
   data.team_name=res[3];
   data.post_tags.push_back(res[4]);
   data.teammates.push_back(res[5]);
   data.project_description=res[6];
   data.diversity=res[7];
   
    return data;
}

ProjectData MainDataBase::SelectPostByProjectname(std::string &project_name)
{
    RowResult res = project_data_table.select("id", "userid", "project_name", "team_name", "post_tag", "teammates", "project_description", "diversity")
   .where("project_name= :param")
   .orderBy("project_name")
   .bind("param",project_name)
   .execute();

   ProjectData data;
   data.id=res[0];
   data.userid=res[1];
   data.project_name=res[2];
   data.team_name=res[3];
   data.post_tags.push_back(res[4]);
   data.teammates.push_back(res[5]);
   data.project_description=res[6];
   data.diversity=res[7];
   
    return data;
}



bool MainDataBase::InsertIntoPostTable(ProjectData &data){
    project_data_table.insert("project_name","team_name","post_tags","teammates","project_description","diversity")
    .values(1, data.project_name)
    .values(2, data.team_name)
    .values(3, data.post_tags[0])
    .values(4, data.teammates[0])
    .values(5, data.project_description)
    .values(6, data.diversity)
    .execute();

    return true;
}

bool MainDataBase::InsertIntoUserTable(RegisterData &data){
    user_data_table.insert("email", "username","password")
    .values(1,data.email)
    .values(2, data.username)
    .values(3, data.password)
    .execute();

    return true;
}



bool MainDataBase::InsertIntoRequestToPostTable(RequestToPostData &data){
    notification_data_table.insert("user_id", "post_id", "motivation_words", "status")    no
    .values(1,data.user_id)
    .values(2, data.post_id)
    .values(3, data.motivation_words)
    .values(4, 3)
    .execute();

    return true;
}


bool MainDataBase::InsertToken(std::string &username, std::string& token){
    token_data_table.insert("username","token")
    .values(1,username)
    .values(2,token)
    .execute();
}

//updatам дописать sql-запросы

bool MainDataBase::EditUserInPersonTable(UserData &data){
    user_data_table.update()
    .set("username",expr(":param1"))
    .set("email",expr(":param2"))
    .set("name",expr(":param3"))
    .set("sur_name",expr(":param4"))
    .set("user_description",expr(":param5"))
    .set("password",expr(":param6"))
    .where("id=param7")
    .bind("param1", data.username)
    .bind("param2", data.email)
    .bind("param3", data.name)
    .bind("param4", data.sur_name)
    .bind("param5", data.user_description)
    .bind("param6", data.password)
    .bind("param7", data.id)
    .execute();

    return true;
}

bool MainDataBase::EditPostInPostTable(ProjectData &data){
    MySQLQuery * updateQuery = new MySQLQuery(sqlconn, "update projectdata set userid=?, project_name=?, team_name=?, post_tags=?,teammates=?,project_description=?, diversity=? where id_project=?")
    updateQuery->setInt(1,data.userid);
    updateQuery->setString(2,data.project_name);
    updateQuery->setString(3,data.team_name);
    updateQuery->setString(4,data.post_tags[0]);
    updateQuery->setString(5,data.teammates[0]);
    updateQuery->setString(6,data.project_description);
    updateQuery->setDouble(7,data.diversity);
    updateQuery->setInt(8,data.id);
    updateQuery->ExecuteUpdate();
    project_data_table.update()
    .set("project_name", expr(":param1"))
    .set("team_name", expr(":param2"))
    .set("post_tags", expr(":param3"))
    .set("teammates", expr(":param4"))
    .set("project_description", expr(":param5"))
    .set("diversity", expr(":param6"))
    .where("id_project", expr(":param7"))
    .bind("param1", data.project_name)
    .bind("param2", data.team_name)
    .bind("param3", data.post_tags)
    .bind("param4", data.teammates)
    .bind("param5", data.project_description)
    .bind("param6", data.diversity)
    .bind("param7", data.id_project)
    .execute();
    return true;
}


bool MainDataBase::EditRequestToPostTable(RequestToPostData &data){
    // MySQLQuery * updateQuery = new MySQLQuery(sqlconn, "update requesttopost set status=? where post_id=?, user_id=?")
    // updateQuery->setInt(1,static_cast<Status>(data.status));
    // updateQuery->setInt(2,data.user_id);
    // updateQuery->setInt(3,data.post_id);

    // updateQuery->ExecuteUpdate();

    return true;
}


bool MainDataBase::IsUnique(std::string &username){
    SqlResult res = user_data_table.select("username")
    .where("username=:param")
    .bind("param",username)
    execute();
    return res.hasData();
}

bool MainDataBase::FindToken(std::string &username, std::string& token){
    SqlResult res = token_data_table.select("username")
    .where("username=:username")
    .bind("param",username)
    execute();
    return res.hasData();
}
