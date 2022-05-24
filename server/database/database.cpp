


MySQLConnection * sqlconn = new MySQLConnection();
sqlconn->Connect("127.0.0.1", 3306, "root", "password", "Projectdata")

bool DelFromTableUser(int id){
    MySQLQuery * que = new MySQLQuery(sqlconn, "DELETE from userdata where id=?");
    que->setInt(1,id);
    return que->ExecuteUpdate();

}
bool DelFromTableToken(int id){
    MySQLQuery * que = new MySQLQuery(sqlconn, "DELETE from tokens where user_id=?");
    que->setInt(1,id);
    return que->ExecuteUpdate();
}

bool DelFromTableProjects(int id){
    MySQLQuery * que = new MySQLQuery(sqlconn, "DELETE from projectdata where project_id=?");
    que->setInt(1,id);
    return que->ExecuteUpdate();
}
bool DelFromTableNotifications(RequestToPostData data){
    MySQLQuery * que = new MySQLQuery(sqlconn, "DELETE from requesttopost where user_id=? and project_id=?");
    que->setInt(1,data->user_id);
    que->setInt(2,data->post_id);
    return que->ExecuteUpdate();
}

std::vector<RequestToPostData> SelectNotifications(int &user_id)
{
    //выводим оповещения-ответы на пост юзера, либо ответы на его отклики
    MySQLQuery * selectQuery = new MySQLQuery(sqlconn, "select r.user_id, \
    r.project_id, p.project_name, r.motivation_words, r.status from requesttopost as r \
    inner join projectdata as p on r.project_id=p.project_id where r.user_id=? and r.status<>3 or p.user_id=?")
    selectQuery->setInt(1,user_id);
    selectQuery->setInt(2,user_id);
    selectQuery->ExecuteQuery();
    std::vector<RequestToPostData> data;

    for (unsigned int i=1; i<=selectQuery->GetResultRowCount(); i++)
    {
        RequestToPostData temp;

        temp.user_id=selectQuery->getInt(i,1);
        temp.post_id=selectQuery->getInt(i,2);
        temp.project_name=selectQuery->getString(i,3);
        temp.motivation_words=selectQuery->getString(i,4);
        // int status=selectQuery->getInt(i,5);
        // if  (status==1){
        //     temp.status=yes;
        //     }
        // else temp.status=no;
        temp.status=static_cast<Status>(selectQuery->getInt(i,5));
        data.push_back(temp);
    }
    return data;
}

UserData FindIntoPersonByUsername(std::string &username){
    MySQLQuery * selectQuery = new MySQLQuery(sqlconn, "select id, username, email, name, sur_name, user_discription, password from userdata "
    R"( where username = ? )");
    selectQuery->setString(1,username);
    selectQuery->ExecuteQuery();
    UserData data;
    data.id=selectQuery->getInt(1,1);
    data.username=selectQuery->getString(1,2);
    data.email=selectQuery->getString(1,3);
    data.name=selectQuery->getString(1,4);
    data.sur_name=selectQuery->getString(1,5);
    data.user_discription=selectQuery->getString(1,6);
    data.password=selectQuery->getString(1,7);
    return data;
}
UserData FindIntoPersonByID(int &id){
    MySQLQuery * selectQuery = new MySQLQuery(sqlconn, "select id, username, email, name, sur_name, user_discription, password from userdata "
    R"( where id = ? )");
    selectQuery->setInt(1,id);
    selectQuery->ExecuteQuery();
    UserData data;
    data.id=selectQuery->getInt(1,1);
    data.username=selectQuery->getString(1,2);
    data.email=selectQuery->getString(1,3);
    data.name=selectQuery->getString(1,4);
    data.sur_name=selectQuery->getString(1,5);
    data.user_discription=selectQuery->getString(1,6);
    data.password=selectQuery->getString(1,7);
    return data;
}

ProjectData SelectPostByID(int &id)
{
   MySQLQuery * selectQuery = new MySQLQuery(sqlconn, "select id, userid, project_name, team_name, post_tag, teammates, project_description, diversity from projectdata "
   "where id=?");
   selectQuery->setInt(1,id)
   selectQuery->ExecuteQuery();
   ProjectData data;
   data.id=selectQuery->getInt(1,1);
   data.userid=selectQuery->getString(1,2);
   data.project_name=selectQuery->getString(1,2);
   data.team_name=selectQuery->getString(1,2);
   data.post_tags.push_back(selectQuery->getString(1,2));
   data.teammates.push_back(selectQuery->getString(1,2));
   data.project_description=selectQuery->getString(1,2);
   data.diversity=selectQuery->getDouble(1,2);

    return data;
}


bool InsertIntoPostTable(ProjectData &data){
    MySQLQuery * insertQuery = new MySQLQuery(sqlconn,"insert into projectdata (userid, project_name,team_name,post_tags,teammates,project_description,diversity) values(?,?,?,?,?,?,?)");
    insertQuery->setInt(1,data.userid);
    insertQuery->setString(2, data.project_name);
    insertQuery->setString(3, data.team_name);
    insertQuery->setString(4, data.post_tags[0]);
    insertQuery->setString(5, data.teammates[0]);
    insertQuery->setString(6, data.project_description);
    insertQuery->setDouble(7, data.diversity);

    insertQuery->ExecuteInsert(); //insert возвращает последнюю строчку доваленную
    return true;
}

bool InsertIntoUserTable(RegisterData &data){
    MySQLQuery * insertQuery = new MySQLQuery(sqlconn,"insert into userdata (email, username,password) values(?,?,?)");
    insertQuery->setString(1,data.email);
    insertQuery->setString(2, data.username);
    insertQuery->setString(3, data.password);
    

    insertQuery->ExecuteInsert(); //insert возвращает последнюю строчку доваленную

    return true;
}



bool InsertIntoRequestToPostTable(RequestToPostData &data){
    MySQLQuery * insertQuery = new MySQLQuery(sqlconn,"insert into requesttopost (user_id, post_id, motivation_words, status) values(?,?,?,?)");
    insertQuery->setInt(1,data.user_id);
    insertQuery->setInt(2, data.post_id);
    insertQuery->setString(3, data.motivation_words);
    insertQuery->setInt(4, 3);   //вставляем по умолчанию тройку, т.к. когда появляется опопвещение по усолчанию ответ на него неизвесте, тое состояние 3
    
    insertQuery->ExecuteInsert(); //insert возвращает последнюю строчку доваленную

    return true;
}


bool InsertToken(std::string &username, std::string& token){
    MySQLQuery * insertQuery = new MySQLQuery(sqlconn,"insert into tokens (username, post_id) values(?,?)");
    insertQuery->setString(1,username);
    insertQuery->setString(2,token);
}

//updatам дописать sql-запросы

bool EditUserInPersonTable(UserData &data){
    MySQLQuery * updateQuery = new MySQLQuery(sqlconn, "update ")
    updateQuery->setString(1,data.username);
    updateQuery->setString(2,data.email);
    updateQuery->setString(3,data.name);
    updateQuery->setString(4,data.sur_name);
    updateQuery->setString(5,data.user_description);
    updateQuery->setString(6,data.password);

    updateQuery->ExecuteUpdate();
    return true;
}

bool EditPostInPostTable(ProjectData &data){
    MySQLQuery * updateQuery = new MySQLQuery(sqlconn, "update ")
    updateQuery->setInt(1,data.userid);
    updateQuery->setString(2,data.project_name);
    updateQuery->setString(3,data.team_name);
    updateQuery->setString(4,data.post_tags[0]);
    updateQuery->setString(5,data.teammates[0]);
    updateQuery->setString(6,data.project_description);
    updateQuery->setDouble(7,data.diversity);

    updateQuery->ExecuteUpdate();

    return true;
}


bool EditRequestToPostTable(RequestToPostData &data){
    MySQLQuery * updateQuery = new MySQLQuery(sqlconn, "update ...")
    updateQuery->setInt(1,static_cast<Status>(data.status));

    updateQuery->ExecuteUpdate();

    return true;
}


bool IsUnique(std::string &username){
    MySQLQuery * selectQuery = new MySQLQuery(sqlconn, "select id from userdata "
    R"( where username = ? )");
    selectQuery->setString(1,username);
    selectQuery->ExecuteQuery();
    if (selectQuery->GetResultRowCount()>0)
    return true;
    else return false;
}











