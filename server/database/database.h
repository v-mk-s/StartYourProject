#pragma once

#include "utils.h"
#include <QObject>
#include <QSqlQueryModel>

class DataBase : public QObject
{
    Q_OBJECT
    public:
        explicit DataBase(QObject *parent = 0);
        ~DataBase();
        void connectToDataBase();
        bool InsertIntoPostTable(const QvariantList &data)
        bool InsertIntoPersonTable(const QvariantList &data)
        bool InsertIntoRequestToPostTable(const QvariantList &data)
        bool DeleteFromPostTable(const QvariantList &data)
        bool DeleteFromPersonTable(const QvariantList &data)
        bool DeleteFromRequestToPostTable(const QvariantList &data)
    private:
        bool openDataBase();
        bool restoreDataBase();
        void closeDataBase();
        bool createPostTable();
        bool createPersonTable();
        bool createRequestToPostTable();
}