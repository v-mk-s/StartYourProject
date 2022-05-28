#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include "register_page.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginPage; }
QT_END_NAMESPACE

class LoginPage : public QWidget
{
    Q_OBJECT

public:
    LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

private slots:
    void on_pushLoginButton_clicked();

    void on_pushGoToRegisterButton_clicked();

private:
    Ui::LoginPage *ui;

    RegisterPage *ui_register;

    // network
    QNetworkAccessManager* networkManager;
    QNetworkAccessManager *networkManagerRight;

    QNetworkAccessManager *networkManagerSetprofile;
    QNetworkAccessManager *networkManagerSetprofileRight;

public slots:

};
#endif // LOGINPAGE_H
