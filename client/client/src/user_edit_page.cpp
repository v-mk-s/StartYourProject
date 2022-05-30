#include "user_edit_page.h"
#include "ui_user_edit_page.h"
#include "utils.hpp"

UserEditPage::UserEditPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserEditPage)
{
    ui->setupUi(this);
}

UserEditPage::~UserEditPage()
{
    delete ui;
}

void UserEditPage::on_pushGoToUserPageButton_clicked()
{

}


void UserEditPage::on_pushSaveButton_clicked()
{
    QString qemail = ui->le_email->text();
    QString qusername = ui->le_username->text();
    QString qpassword = ui->le_password->text();
    QString qname = ui->le_name->text();
    QString qsurname = ui->le_surname->text();

    std::string email = qemail.toUtf8().constData();
    std::string username = qusername.toUtf8().constData();
    std::string password = qpassword.toUtf8().constData();
    std::string name = qname.toUtf8().constData();
    std::string surname = qsurname.toUtf8().constData();

    UserData user_edit_data;

    user_edit_data.email = email;
    user_edit_data.username = username;
    user_edit_data.password = password;
    user_edit_data.name = name;
    user_edit_data.surname = surname;
}


void UserEditPage::on_pushAddPhotoButton_clicked()
{

}


void UserEditPage::on_pushLogOutButton_clicked()
{

}

