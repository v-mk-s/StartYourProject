#include "user_page.h"
#include "ui_user_page.h"

UserPage::UserPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserPage)
{
    ui->setupUi(this);
}

UserPage::~UserPage()
{
    delete ui;
}

void UserPage::on_pushSearchButton_clicked()
{

}


void UserPage::on_pushRequestToProjectButton_clicked()
{

}


void UserPage::on_pushBackButton_clicked()
{

}


void UserPage::on_pushLogOutButton_clicked()
{

}


void UserPage::on_pushProject1DelButton_clicked()
{

}

