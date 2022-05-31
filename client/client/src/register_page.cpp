#include "register_page.h"
#include "ui_register_page.h"
#include "utils.hpp"
#include "usecases.hpp"
#include <QJsonObject>
#include <QUrl>
#include <QJsonDocument>
#include <iostream>

#include <QMessageBox>

RegisterPage::RegisterPage(QWidget *parent) :
    QWidget(parent)
    , ui(new Ui::RegisterPage)
    , registerNetworkManager(new QNetworkAccessManager)
{
    ui->setupUi(this);
}

RegisterPage::~RegisterPage()
{
    delete ui;
}

void RegisterPage::on_pushGoToLoginButton_clicked()
{
    this->close();
    emit goToLoginPage();
}


void RegisterPage::on_pushRegisterButton_clicked()
{
    QString qemail = ui->le_email->text();
    QString qusername = ui->le_username->text();
    QString qpassword = ui->le_password->text();

    std::string email = qemail.toUtf8().constData();
    std::string username = qusername.toUtf8().constData();
    std::string password = qpassword.toUtf8().constData();

    UserData register_data;
    register_data.email = email;
    register_data.username = username;
    register_data.password = password;

    RegisterUC register_uc;

    if (register_uc.onRegisterButton(register_data) == ErrorStatus::no_error) {
        QJsonObject param;
        param.insert("username", qusername);
        param.insert("password", qpassword);
        param.insert("email", qemail);

        QJsonDocument doc(param);
        QString strJson(doc.toJson(QJsonDocument::Compact));

        QNetworkRequest request;
        request.setUrl(QUrl(QString::fromStdString(std::string(URL) + REGISTER_URL)));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setHeader(QNetworkRequest::ContentLengthHeader, strJson.length());

        auto responce = registerNetworkManager->post(request,
                                                  strJson.toStdString().data());
        // attention
//        responce->setParent(loginNetworkManager->get(request));
        connect(responce, &QNetworkReply::finished, [=]() {
            if (responce->error() == QNetworkReply::NoError) {
//            std::vector<char> body;
//            auto bodyByteArray = responce->readAll();
//            body.reserve(bodyByteArray.size());
//            std::memcpy(body.data(), bodyByteArray.data(), body.capacity());
//            responce->deleteLater();
                QMessageBox::about(this, "Registration", "Successed registration.\n NOW Start Your Project!");

                this->close();
                emit goToLoginPage();
            } else {
                qDebug("Register Error");
            }

        });


    } else {
        QMessageBox::warning(this, "Validation", "Incorrect input data");
    }
}



