#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include "register_page.h"
#include "user_page.h"
#include "utils.hpp"
#include "general.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginPage; }
QT_END_NAMESPACE

class LoginPage : public QWidget
{
    Q_OBJECT

public:
    LoginPage(std::shared_ptr<Context> context = nullptr, QWidget *parent = nullptr);
    ~LoginPage();

//    void setUserAuthToken(std::string auth_token) { _context->getUserData().auth_token = auth_token; }
//    void setUserUsername(std::string username) { _context->getUserData().username = username; }
//    void setUserPassword(std::string password) { _context->getUserData().password = password; }

private slots:
    void on_pushLoginButton_clicked();

    void on_pushGoToRegisterButton_clicked();

public slots:


private:
    Ui::LoginPage *ui;

    RegisterPage* register_ui;
    UserPage* user_ui;

//    UserData _user_data;
    std::shared_ptr<Context> _context;


    // network
    QNetworkAccessManager* loginNetworkManager;

};
#endif // LOGINPAGE_H
