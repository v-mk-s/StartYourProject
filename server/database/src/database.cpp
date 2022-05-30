#include "database.hpp"


mysqlx::Table CreateTable(mysqlx::Session &session, const mysqlx::string &name, const mysqlx::string &params) {
    std::cout<<"Creating table"<<std::endl;
    mysqlx::string quoted_name = mysqlx::string("`")
    + session.getDefaultSchemaName()
    + mysqlx::string(L"`.`") + name + mysqlx::string(L"`");
    mysqlx::string create = "CREATE TABLE IF NOT EXISTS ";
    create += quoted_name;
    create += params;
    session.sql(create).execute();
    return session.getDefaultSchema().getTable(name);
}

MainDataBase::MainDataBase(): 
    cli("root:123qwerty@localhost:33060/"SYP_DB_NAME, mysqlx::ClientOption::POOL_MAX_SIZE, 7),
    sqlconn(cli.getSession()) {
    //mysqlx::Session(HOST, PORT, DB_USER, DB_PASSWORD)
    sqlconn.sql("CREATE DATABASE IF NOT EXISTS "SYP_DB_NAME";").execute();
    // sqlconn.sql("use SYP_DB;");

    // sqlconn.sql("use SYP_DB; create table IF NOT EXISTS tags_data (id int auto_increment, tag char(30) unique,PRIMARY KEY ( id ) );");
        
    // sqlconn.sql("use SYP_DB; CREATE TABLE IF NOT EXISTS user_data  ( user_name  CHAR(32) NOT NULL, email  CHAR(32),  name  CHAR(32),"
    //             " sur_name  CHAR(32), user_discription  CHAR(255), password  CHAR(64) NOT NULL, PRIMARY KEY ( user_name ));");
                    
    // sqlconn.sql("use SYP_DB; CREATE TABLE IF NOT EXISTS project_data  ( user_name  char(32) NOT NULL, project_name  char(32),"
    //             " team_name  char(32),  project_description  char(255),  diversity  double, primary key( project_name ),"
    //             " foreign key ( user_name ) references user_data( user_name ));");
                    
    // db = std::make_unique<mysqlx::Schema>(sqlconn.getSchema("SYP_DB"));

    user_data_table = std::make_unique<mysqlx::Table>(
        CreateTable(sqlconn, USER_TABLE, "( user_name  CHAR(32) NOT NULL, email  CHAR(32),  name  CHAR(32),"
                " sur_name  CHAR(32), user_discription  CHAR(255), password  CHAR(64) NOT NULL, PRIMARY KEY ( user_name ))")
    );
    project_data_table = std::make_unique<mysqlx::Table>(
        CreateTable(sqlconn, PROJECT_TABLE,"( user_name  char(32) NOT NULL, project_name  char(32),  team_name  char(32),  project_description  char(255),  diversity  double, primary key( project_name ), foreign key ( user_name ) references user_data( user_name ))" ));
        
    token_data_table = std::make_unique<mysqlx::Table>(CreateTable(sqlconn, TOKEN_TABLE,
                                                       "( token char(100), user_name  CHAR(32) NOT NULL unique,primary key (token),"
                                                       " FOREIGN KEY (user_name)  REFERENCES user_data (user_name))"));
    notification_data_table = std::make_unique<mysqlx::Table>(CreateTable(sqlconn, NOTIFICATION_TABLE,  "id  int NOT NULL AUTO_INCREMENT, project_name  char(32) NOT NULL, motivation_words  char(255),user_name char(32) not null,status int, primary key( id ), foreign key ( project_name ) references project_data(project_name ), foreign key ( user_name ) references user_data( user_name ))"));
    team_data_table = std::make_unique<mysqlx::Table>(CreateTable(sqlconn, TEAM_TABLE, "(user_name char(32) not null, project_name char(32) not null,foreign key ( user_name ) references user_data( user_name ),foreign key ( project_name ) references project_data( project_name ), unique(user_name,project_name) )"));
    tags_data_table = std::make_unique<mysqlx::Table>(CreateTable(sqlconn, TAGS_TABLE, "(id int auto_increment, tag char(30) unique,PRIMARY KEY ( id ) )"));
    user_tags_data = std::make_unique<mysqlx::Table>(CreateTable(sqlconn, USER_TAGS_TABLE, "(user_name char(32) not null, id_tag int not null, foreign key ( user_name ) references user_data( user_name ),foreign key ( id_tag ) references tags_data( id ), unique(user_name,id_tag))"));
    project_tags_data = std::make_unique<mysqlx::Table>(CreateTable(sqlconn, PROJECT_TAGS_TABLE, "(project_name char(32) not null, id_tag int not null, foreign key ( project_name ) references project_data( project_name ),foreign key ( id_tag ) references tags_data( id ), unique(project_name,id_tag))"));
    // db = std::make_unique<mysqlx::Schema>(sqlconn.getSchema("SYP_DB"));
    // user_data_table = std::make_unique<mysqlx::Table>(db->getTable("user_data"));
    // project_data_table = std::make_unique<mysqlx::Table>(db->getTable("project_data"));
    // token_data_table = std::make_unique<mysqlx::Table>(db->getTable("token_data"));
    // notification_data_table = std::make_unique<mysqlx::Table>(db->getTable("notification_data"));

        // CREATE DATABASE IF NOT EXISTS SYP_DB;
        // use SYP_DB;
        // create table IF NOT EXISTS tags_data (id int auto_increment, tag char(30) unique,PRIMARY KEY ( id ) );
        // CREATE TABLE IF NOT EXISTS user_data  ( user_name  CHAR(32) NOT NULL, email  CHAR(32),  name  CHAR(32), sur_name  CHAR(32), user_discription  CHAR(255), password  CHAR(64) NOT NULL, PRIMARY KEY ( user_name ));
        // CREATE TABLE IF NOT EXISTS project_data  ( user_name  char(32) NOT NULL, project_name  char(32),  team_name  char(32),  project_description  char(255),  diversity  double, primary key( project_name ), foreign key ( user_name ) references user_data( user_name ));
        // create table IF NOT EXISTS team_data (user_name char(32) not null, project_name char(32) not null,foreign key ( user_name ) references user_data( user_name ),foreign key ( project_name ) references project_data( project_name ), unique(user_name,project_name) );
        // create table IF NOT EXISTS user_tags_data (user_name char(32) not null, id_tag int not null, foreign key ( user_name ) references user_data( user_name ),foreign key ( id_tag ) references tags_data( id ), unique(user_name,id_tag));
        // CREATE TABLE IF NOT EXISTS  token_data  ( token char(100), user_name  CHAR(32) NOT NULL unique,primary key (token), FOREIGN KEY (user_name)  REFERENCES user_data (user_name));
        // CREATE TABLE IF NOT EXISTS notification_data ( id  int NOT NULL AUTO_INCREMENT, project_name  char(32) NOT NULL, motivation_words  char(255),user_name char(32) not null,status int, primary key( id ), foreign key ( project_name ) references project_data(project_name ), foreign key ( user_name ) references user_data( user_name ));
        // create table IF NOT EXISTS project_tags_data (project_name char(32) not null, id_tag int not null, foreign key ( project_name ) references project_data( project_name ),foreign key ( id_tag ) references tags_data( id ), unique(project_name,id_tag));

    std::list<mysqlx::Schema> schemaList = sqlconn.getSchemas();

    std::cout << "Available schemas in this session:" << std::endl;


    // Loop over all available schemas and print their name
    for (mysqlx::Schema schema : schemaList) {
        std::cout << schema.getName() << std::endl;
    }
}




MainDataBase::~MainDataBase() {
    sqlconn.close();
}



DBStatus MainDataBase::DeleteFromPersonTable(std::string &username) {
    std::cout << "DeleteFromPersonTable:" << std::endl;

    user_data_table->remove()
    .where("user_name=:param")
    .bind("param",username)
    .execute();
    return DBStatus::ok;
}
DBStatus MainDataBase::DeleteToken(std::string& username) {
    std::cout << "DeleteToken:" << std::endl;

    token_data_table->remove()
    .where("username=:param")
    .bind("param",username)
    .execute();
    return DBStatus::ok;
}

DBStatus MainDataBase::DeleteFromPostTable(std::string& username) {
    std::cout << "DeleteFromPostTable:" << std::endl;
    
    // MySQLQuery * que = new MySQLQuery(sqlconn, "DELETE from projectdata where project_id=?");
    // que->setInt(1,id);
    // return que->ExecuteUpdate();

    return DBStatus::ok;
}

DBStatus MainDataBase::DelFromTableNotifications(RequestToPostData& data) {
    std::cout << "DelFromTableNotifications:" << std::endl;
    

    // MySQLQuery * que = new MySQLQuery(sqlconn, "DELETE from requesttopost where user_id=? and project_id=?");
    // que->setInt(1,data.user_id);
    // que->setInt(2,data.post_id);
    // return que->ExecuteUpdate();
    project_data_table->remove()
    .where("project_name=:param")
    .bind("param",data.project_name)
    .execute();
    return DBStatus::ok;

}
DBStatus MainDataBase::DeleteFromRequestToPostTable(RequestToPostData &data) {
    std::cout << "DeleteFromRequestToPostTable:" << std::endl;
    // MySQLQuery * que = new MySQLQuery(sqlconn, "DELETE from requesttopost where user_id=? and project_id=?");

    return DBStatus::ok;
}

Message<std::vector<RequestToPostData>, DBStatus> MainDataBase::FindRequestToPostTable(std::string &username) {
    std::cout << "FindRequestToPostTable:" << std::endl;
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
    std::cout << "FindIntoPersonByUsername:" << std::endl;
    mysqlx::RowResult res = user_data_table->select( "user_name", "email", "name", "sur_name", "user_discription", "password")
    .where("user_name = :param")
    .orderBy("name")
    .bind("param",username)
    .execute();
    
    UserData data;
    mysqlx::Row row = res.fetchOne();

    data.username = std::string(row[0]);
    data.email = std::string(row[1]);
    data.name = std::string(row[2]);
    data.sur_name = std::string(row[3]);
    data.user_discription = std::string(row[4]);
    data.password = std::string(row[5]);
    return Message<UserData, DBStatus>(data);
}

// UserData MainDataBase::FindIntoPersonByID(int id) {
//     mysqlx::RowResult res = user_data_table->select("id", "user_name", "email", "name", "sur_name", "user_discription", "password")
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
//     mysqlx::RowResult res = project_data_table->select("id", "userid", "project_name", "team_name", "post_tag", "teammates", "project_description", "diversity")
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
//     mysqlx::RowResult res = project_data_table->select("id", "userid", "project_name", "team_name", "post_tag", "teammates", "project_description", "diversity")
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
    std::cout << "InsertIntoPostTable:" << std::endl;
    project_data_table->insert("project_name","team_name","post_tags","teammates","project_description","diversity")
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
    std::cout << "InsertIntoUserTable:" << std::endl;
    user_data_table->insert("email", "user_name","password")
    .values(1,data.email)
    .values(2, data.username)
    .values(3, data.password)
    .execute();

    return DBStatus::ok;
}



DBStatus MainDataBase::InsertIntoRequestToPostTable(RequestToPostData &data) {
    std::cout << "InsertIntoRequestToPostTable:" << std::endl;
    // notification_data_table.insert("user_name", "post_id", "motivation_words", "status")
    // .values(1,data.user_name)
    // .values(2, data.post_id)
    // .values(3, data.motivation_words)
    // .values(4, 3)
    // .execute();

    return DBStatus::ok;
}


DBStatus MainDataBase::InsertToken(std::string &username, std::string& token) {
    std::cout << "InsertToken:" << std::endl;
    token_data_table->insert("user_name","token")
    .values(1,username)
    .values(2,token)
    .execute();
}

//updatам дописать sql-запросы

DBStatus MainDataBase::EditUserInPersonTable(UserData &data) {
    std::cout << "EditUserInPersonTable:" << std::endl;
    user_data_table->update()
    .set("user_name", mysqlx::expr(":param1"))
    .set("email", mysqlx::expr(":param2"))
    .set("name", mysqlx::expr(":param3"))
    .set("sur_name", mysqlx::expr(":param4"))
    .set("user_description", mysqlx::expr(":param5"))
    .set("password", mysqlx::expr(":param6"))
    .where("username=:param7")
    .bind("param1", data.username)
    .bind("param2", data.email)
    .bind("param3", data.name)
    .bind("param4", data.sur_name)
    .bind("param5", data.user_discription)
    .bind("param6", data.password)
    .bind("param7", data.username)
    .execute();

    return DBStatus::ok;
}

DBStatus MainDataBase::EditPostInPostTable(ProjectData &data) {
    std::cout << "EditPostInPostTable:" << std::endl;
    project_data_table->update()
    .set("project_name", mysqlx::expr(":param1"))
    .set("team_name", mysqlx::expr(":param2"))
    .set("post_tags", mysqlx::expr(":param3"))
    .set("teammates", mysqlx::expr(":param4"))
    .set("project_description", mysqlx::expr(":param5"))
    .set("diversity", mysqlx::expr(":param6"))
    .where("project_name=:param7")
    .bind("param1", data.project_name)
    .bind("param2", data.team_name)
    .bind("param3", data.post_tags[0])
    .bind("param4", data.teammates[0])
    .bind("param5", data.project_description)
    .bind("param6", data.diversity)
    .bind("param7", data.project_name)
    .execute();
    return DBStatus::ok;
}


DBStatus MainDataBase::EditRequestToPostTable(RequestToPostData &data){
    std::cout << "EditRequestToPostTable:" << std::endl;
    // MySQLQuery * updateQuery = new MySQLQuery(sqlconn, "update requesttopost set status=? where post_id=?, user_id=?")
    // updateQuery->setInt(1,static_cast<Status>(data.status));
    // updateQuery->setInt(2,data.user_id);
    // updateQuery->setInt(3,data.post_id);

    // updateQuery->ExecuteUpdate();

    return DBStatus::ok;
}


// DBStatus MainDataBase::IsUnique(std::string &username) {
//     mysqlx::RowResult res = user_data_table->select("username")
//     .where("username=:param")
//     .bind("param", username)
//     .execute();
//     return res.();
// }

bool MainDataBase::CheckToken(std::string &username, std::string& token) {
    std::cout << "CheckToken:" << std::endl;
    mysqlx::SqlResult res = sqlconn.sql("select * from token_data where  username=:param")
    .bind("param", username)
    .execute();
    return res.hasData();
}

Message<ProjectData, DBStatus> MainDataBase::FindIntoPostTable(std::string &project_name) {
    std::cout << "FindIntoPostTable:" << std::endl;
    return DBStatus::ok;
}
