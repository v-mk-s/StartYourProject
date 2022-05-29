#include "publish_post_page.h"
#include "ui_publish_post_page.h"
#include "utils.hpp"
#include "general.h"
#include "usecases.hpp"
#include <QMessageBox>
#include <vector>

PublishPostPage::PublishPostPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PublishPostPage)
{
    ui->setupUi(this);
}

PublishPostPage::~PublishPostPage()
{
    delete ui;
}

void PublishPostPage::on_pushSavePublishButton_clicked()
{
    QString qproject_name = ui->le_project_name->text();
    QString qteam_name = ui->le_team_name->text();
    QString qteammates = ui->le_teammates->text();
    QString qpost_tags = ui->le_post_tags->text();
    QString qproject_description = ui->le_project_descr->text();

    std::string project_name = qproject_name.toUtf8().constData();
    std::string team_name = qteam_name.toUtf8().constData();
    std::string teammates_str = qteammates.toUtf8().constData();
    std::string post_tags_str = qpost_tags.toUtf8().constData();
    std::string project_description = qproject_description.toUtf8().constData();

    std::vector<std::string> teammates = getVectorFromString(teammates_str);

    std::vector<std::string> post_tags = getVectorFromString(post_tags_str);


    ProjectData project_data;

    project_data.project_name = project_name;
    project_data.team_name = team_name;
    project_data.teammates = teammates;
    project_data.post_tags = post_tags;
    project_data.project_description = project_description;

    PublishPostUC publish_post_uc;

    if (publish_post_uc.onGetDataButton(project_data) == ErrorStatus::no_error) {

    } else {
        QMessageBox::warning(this, "Validation", "Not correct input data");
    }

}


