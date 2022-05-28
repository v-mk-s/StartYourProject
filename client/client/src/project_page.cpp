#include "project_page.h"
#include "ui_project_page.h"

ProjectPage::ProjectPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectPage)
{
    ui->setupUi(this);
}

ProjectPage::~ProjectPage()
{
    delete ui;
}

void ProjectPage::on_pushSearchButton_clicked()
{
    QString qsearch = ui->le_search->text();

    std::string search = qsearch.toUtf8().constData();


}



void ProjectPage::on_checkIsUserBox_stateChanged(int arg1)
{
    if (ui->checkIsUserBox->isChecked()) {
        search = SearchValue::user;
    } else {
        search = SearchValue::project;
    }
}

