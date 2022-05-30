#include "register_page.h"
#include "ui_register_page.h"
#include "utils.hpp"
#include "usecases.hpp"

#include <QMessageBox>

RegisterPage::RegisterPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterPage)
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

    } else {
        QMessageBox::warning(this, "Validation", "Not correct input data");
    }
}



