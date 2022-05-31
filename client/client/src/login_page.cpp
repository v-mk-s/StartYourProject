#include "login_page.h"
#include "ui_login_page.h"
#include "utils.hpp"
#include "usecases.hpp"
#include <QMessageBox>
#include <QJsonObject>
#include <QUrl>
#include <QJsonDocument>
#include "general.h"

#include <iostream>

LoginPage::LoginPage(std::shared_ptr<Context> context, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginPage)
    , loginNetworkManager(new QNetworkAccessManager)
    , _context(context)
{
    ui->setupUi(this);

    QWidget* register_widget = nullptr;
    register_ui = new RegisterPage(register_widget);
    connect(register_ui, &RegisterPage::goToLoginPage, this, &LoginPage::show);

}



LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::on_pushLoginButton_clicked()
{
    QString qusername = ui->le_login->text();
    QString qpassword = ui->le_password->text();

    std::string username = qusername.toUtf8().constData();
    std::string password = qpassword.toUtf8().constData();

    _context->getUserData().username = username;
    _context->getUserData().password = password;

    LoginUC login_uc;

    if (login_uc.onLoginButton(_context->getUserData()) == ErrorStatus::no_error) {

        QJsonObject param;
        param.insert("username", qusername);
        param.insert("password", qpassword);


        QJsonDocument doc(param);
        QString strJson(doc.toJson(QJsonDocument::Compact));

        QNetworkRequest request;
        request.setUrl(QUrl(QString::fromStdString(std::string(URL) + LOGIN_URL)));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setHeader(QNetworkRequest::ContentLengthHeader, strJson.length());

        auto responce = loginNetworkManager->post(request,
                                                  strJson.toStdString().data());
        // attention
//        responce->setParent(loginNetworkManager->get(request));

        connect(responce, &QNetworkReply::finished, [=]() {
            if (responce->error() == QNetworkReply::NoError) {

//                std::vector<char> body;
//                auto bodyByteArray = responce->readAll();
//                body.reserve(bodyByteArray.size());
//                std::memcpy(body.data(), bodyByteArray.data(), body.capacity());
//                responce->deleteLater();

                QByteArray reply = responce->readAll();
                std::string auth_token_reply = reply.toStdString();

                _context->setAuthTokenUserData(auth_token_reply);
                _context->setUsernameUserData(username);
                _context->setPasswordUserData(password);

                std::cout << _context->getUserData().auth_token << " test" << std::endl;

                QMessageBox::warning(this, "На вратах ада было написано", "Оставь надежду, всяк сюда входящий!");

                // goToUserPage
                QWidget* user_widget = nullptr;
                user_ui = new UserPage(user_widget, _context);
                connect(user_ui, &UserPage::LogOut, this, &LoginPage::show);

                user_ui->show();

                this->close();

            } else {
                qDebug("Login Error");
            }
        });

    } else {
        QMessageBox::warning(this, "Validation", "Try again!");
    }
}


void LoginPage::on_pushGoToRegisterButton_clicked()
{
    register_ui->show();
    this->close();
}

