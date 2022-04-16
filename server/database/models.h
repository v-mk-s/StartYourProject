#include <QObject>
#include <QSqlQueryModel>
 
class ModelPostData : public QSqlQueryModel
{
    Q_OBJECT
public:
    // Перечисляем все роли, которые будут использоваться в TableView
    enum Roles {
        author_id_role,
        project_name_role,
        postdescription_role,
        tags_role,
        team_name_role,
        date_role = Qt::UserRole + 1
    };
    // объявляем конструктор класса
    explicit ModelPostData(QObject *parent = 0);
 
    // Переопределяем метод, который будет возвращать данные
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
 
protected:
    /* хешированная таблица ролей для колонок.
     * Метод используется в дебрях базового класса QAbstractItemModel,
     * от которого наследован класс QSqlQueryModel
     * */
    QHash<int, QByteArray> roleNames() const;
    
};
 
class ModelUserData : public QSqlQueryModel
{
    Q_OBJECT
public:
    enum Roles {
        user_id_role,
        user_name_role,
        email_role,
        name_role,
        sur_name_role,
        user_discription_role,
        password_role
    };
    explicit ModelUserData(QObject *parent = 0);
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
protected:
    QHash<int, QByteArray> roleNames() const;
};



class ModelReqToPostData : public QSqlQueryModel
{
    Q_OBJECT
public:
    enum Roles {
        user_id_role,
        post_id_role,
        description_role
    };
    explicit ModelReqToPostData(QObject *parent = 0);

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
protected:
    QHash<int, QByteArray> roleNames() const;
};

#endif 