#pragma once

#include <vector>
#include "idatabase.hpp"

class ModelPostData 
{
    public:
    
    // объявляем конструктор класса
    explicit ModelPostData(MainDataBase *db );
 
    // Метод, который будет возвращать данные
    PostData* ViewData(PostData *data);
 
protected:

    std::vector <PostData> data_string;
    
};
 
class ModelUserData
{
    public:
    
    // объявляем конструктор класса
    explicit ModelUserData(MainDataBase *db );
 
    // Метод, который будет возвращать данные
    UserData* ViewData(UserData *data);
 
protected:

    std::vector <UserData> data_string;
    
};



class ModelRequestToPostData
{
    public:
    
    // объявляем конструктор класса
    explicit ModelRequestToPostData(MainDataBase *db );
 
    // Метод, который будет возвращать данные
    RequestToPostData* ViewData(RequestToPostData *data);
 
protected:

    std::vector <RequestToPostData> data_string;
    
};
