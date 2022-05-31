#ifndef USER_PAGE_H
#define USER_PAGE_H

#include <QWidget>
#include "utils.hpp"
#include "user_edit_page.h"
#include "project_page.h"
#include "publish_post_page.h"
#include "look_for_user.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

#include "general.h"

namespace Ui {
class UserPage;
}

class UserPage : public QWidget
{
    Q_OBJECT

public:
    explicit UserPage(QWidget *parent = nullptr, std::shared_ptr<Context> context = nullptr);
    ~UserPage();

//    void getUserData(const UserData& user_data);

signals:
    void LogOut();

    void goToProjectPage();
    void goToMainUser();
//    void goToPublishPostPage();
//    void goToProjectPage();
//    void getUserData();


private slots:
    void on_pushSearchProjectButton_clicked();

//    void on_pushRequestToProjectButton_clicked();

    void on_pushBackButton_clicked();

    void on_pushLogOutButton_clicked();

//    void on_pushProject1DelButton_clicked();

    void on_pushUserEditButton_clicked();

    void on_pushPublishPostButton_clicked();

    void on_pushSearchUserButton_clicked();

private:
    Ui::UserPage *ui;

    UserEditPage *user_edit_ui;
    PublishPostPage *publish_post_ui;
    ProjectPage *project_ui;
    LookForUser *look_for_user_ui;

    std::shared_ptr<Context> _context;

    QNetworkAccessManager* userNetworkManager;
};

#endif // USER_PAGE_H
