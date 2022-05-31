#include "user_edit_page.h"
#include "ui_user_edit_page.h"
#include "utils.hpp"
#include "usecases.hpp"
#include <QJsonObject>
#include <QUrl>
#include <QJsonDocument>
#include <iostream>
#include <QMessageBox>

UserEditPage::UserEditPage(QWidget *parent, std::shared_ptr<Context> context) :
    QWidget(parent)
    , ui(new Ui::UserEditPage)
    , userEditNetworkManager(new QNetworkAccessManager)
    , _context(context)
{
    ui->setupUi(this);
}

UserEditPage::~UserEditPage()
{
    delete ui;
}

void UserEditPage::on_pushGoToUserPageButton_clicked()
{
    this->close();
    emit goToUserPage();
}


void UserEditPage::on_pushSaveButton_clicked()
{
    QString qauth_token = QString::fromStdString(_context->getUserData().auth_token);
    QString qemail = ui->le_email->text();
    QString qusername = ui->le_username->text();
    QString qpassword = ui->le_password->text();
    QString qname = ui->le_name->text();
    QString qsurname = ui->le_surname->text();
    QString quser_description = ui->le_user_description->text();

    std::string email = qemail.toUtf8().constData();
    std::string username = qusername.toUtf8().constData();
    std::string password = qpassword.toUtf8().constData();
    std::string name = qname.toUtf8().constData();
    std::string surname = qsurname.toUtf8().constData();
    std::string user_description = quser_description.toUtf8().constData();

    UserEditUC user_edit_uc;

    UserData _tmp_user;
    _tmp_user.email = email;
    _tmp_user.username = username;
    _tmp_user.password = password;
    _tmp_user.name = name;
    _tmp_user.sur_name = surname;
    _tmp_user.user_discription = user_description;


    if (user_edit_uc.onEditUserDataButton(_tmp_user) == ErrorStatus::no_error) {

        QJsonObject param;
        param.insert("username", qusername);
        param.insert("password", qpassword);
        param.insert("auth_token", qauth_token);
        param.insert("email", qemail);
        param.insert("name", qname);
        param.insert("surname", qsurname);
        param.insert("user_discription", quser_description);


        QJsonDocument doc(param);
        QString strJson(doc.toJson(QJsonDocument::Compact));

        QNetworkRequest request;
        request.setUrl(QUrl(QString::fromStdString(std::string(URL) + EDIT_PROFILE_URL)));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setHeader(QNetworkRequest::ContentLengthHeader, strJson.length());

//        std::cout << strJson.length() << std::endl;

        auto responce = userEditNetworkManager->post(request,
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

                std::cout << _context->getUserData().auth_token << " test" << std::endl;

                _context->setEmailUserData(email);
                _context->setUsernameUserData(username);
                _context->setPasswordUserData(password);
                _context->setNameUserData(name);
                _context->setSurnameUserData(surname);
                _context->setUserDescriptionUserData(user_description);

                QMessageBox::information(this, "Information", "New User data was written");

            } else {
                qDebug("UserEdit Error");
            }
        });
    } else {
        QMessageBox::about(this, "Validation", "Incorrect input data");
    }
}


void UserEditPage::on_pushAddPhotoButton_clicked()
{

}


void UserEditPage::on_pushLogOutButton_clicked()
{

}

