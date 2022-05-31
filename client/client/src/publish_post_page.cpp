#include "publish_post_page.h"
#include "ui_publish_post_page.h"
#include "utils.hpp"
#include "general.h"
#include "usecases.hpp"

#include <QMessageBox>
#include <vector>
#include <QJsonObject>
#include <QUrl>
#include <QJsonDocument>
#include <iostream>

PublishPostPage::PublishPostPage(QWidget *parent, std::shared_ptr<Context> context) :
    QWidget(parent)
    , ui(new Ui::PublishPostPage)
    , publishPostNetworkManager(new QNetworkAccessManager)
    , _context(context)
{
    ui->setupUi(this);
}

PublishPostPage::~PublishPostPage()
{
    delete ui;
}

void PublishPostPage::on_pushSavePublishButton_clicked()
{
    QString qauth_token = QString::fromStdString(_context->getUserData().auth_token);
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

    _context->getProjectData().project_name = project_name;
    _context->getProjectData().team_name = team_name;
    _context->getProjectData().teammates = teammates;
    _context->getProjectData().post_tags = post_tags;
    _context->getProjectData().project_description = project_description;

    PublishPostUC publish_post_uc;

    if (publish_post_uc.onGetDataButton(_context->getProjectData()) == ErrorStatus::no_error) {
        QJsonObject param;
        param.insert("auth_token", qauth_token);
        param.insert("project_name", qproject_name);
        param.insert("team_name", qteam_name);
        param.insert("teammates", qteammates);
        param.insert("project_discription", qproject_description);
//        add post_tags
//        param.insert("post_tags", qpost_tags);

        QJsonDocument doc(param);
        QString strJson(doc.toJson(QJsonDocument::Compact));

        QNetworkRequest request;
        request.setUrl(QUrl(QString::fromStdString(std::string(URL) + CREATE_POST_URL)));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setHeader(QNetworkRequest::ContentLengthHeader, strJson.length());

        auto responce = publishPostNetworkManager->post(request,
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

//                std::cout << _user_data.auth_token << " test" << std::endl;

                QMessageBox::information(this, "Information", "New Post was published");

            } else {
                qDebug("PublishPost Error");
            }
        });
    } else {
        QMessageBox::warning(this, "Validation", "Not correct input data");
    }

}



void PublishPostPage::on_pushBackButton_clicked()
{
    this->close();
    emit goToUserPage();
}

