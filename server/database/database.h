#include "../utils.h"



class MainDataBase
{
    public:
        explicit MainDataBase();
        ~MainDataBase();
        void connectToDataBase();
        bool InsertIntoPostTable( PostData &data);
        bool InsertIntoPersonTable( UserData &data);
        bool InsertIntoRequestToPostTable(RequestToPostData &data);
        bool DeleteFromPostTable(PostData &data);
        bool DeleteFromPersonTable(UserData &data);
        bool DeleteFromRequestToPostTable(RequestToPostData &data);
    private:
        bool openDataBase();
        bool restoreDataBase();
        void closeDataBase();
        bool createPostTable();
        bool createPersonTable();
        bool createRequestToPostTable();
};