#include "login_page.h"
#include "ui_login_page.h"
#include "utils.hpp"
#include "usecases.hpp"
#include <QMessageBox>

LoginPage::LoginPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);

    ui_register = new RegisterPage();
    connect(ui_register, &RegisterPage::goToLoginPage, this, &LoginPage::show);
}

LoginPage::~LoginPage()
{
    delete ui;
}


// need impl
void LoginPage::on_pushLoginButton_clicked()
{
    QString qusername = ui->le_login->text();
    QString qpassword = ui->le_password->text();

    std::string username = qusername.toUtf8().constData();
    std::string password = qpassword.toUtf8().constData();

    UserData login_data;
    login_data.username = username;
    login_data.password = password;

    LoginUC login_uc;

    if (login_uc.onLoginButton(login_data) == ErrorStatus::no_error) {
        QMessageBox::warning(this, "Validation", "username input data");
    } else {
        QMessageBox::warning(this, "Validation", "Try again!");
    }
}


void LoginPage::on_pushGoToRegisterButton_clicked()
{

    ui_register->show();
    this->close();
}

