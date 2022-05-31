#include "project_page.h"
#include "ui_project_page.h"
#include "usecases.hpp"
#include "utils.hpp"

#include <QMessageBox>
#include <QJsonObject>
#include <QUrl>
#include <QJsonDocument>
#include <iostream>
#include <QJsonArray>

ProjectPage::ProjectPage(QWidget *parent, std::shared_ptr<Context> context) :
    QWidget(parent)
    , ui(new Ui::ProjectPage)
    , projectNetworkManager(new QNetworkAccessManager)
    , _context(context)
{
    ui->setupUi(this);
}

ProjectPage::~ProjectPage()
{
    delete ui;
}

void ProjectPage::on_pushSearchButton_clicked()
{
    QString qproject_name = ui->le_search->text();

    std::string project_name = qproject_name.toUtf8().constData();

    QJsonObject param;
    param.insert("project_name", qproject_name);

    QJsonDocument doc(param);
    QString strJson(doc.toJson(QJsonDocument::Compact));

    QNetworkRequest request;
    request.setUrl(QUrl(QString::fromStdString(std::string(URL) + FIND_POST_URL)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setHeader(QNetworkRequest::ContentLengthHeader, strJson.length());

    auto responce = projectNetworkManager->post(request,
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
            QJsonDocument doc = QJsonDocument::fromJson(reply);
            QJsonObject json = doc.object();

            QString qteam_name = json["team_name"].toString();
            QString qproject_description = json["project_description"].toString();

//          qteammates
            QVector<QString> qteammates_vec;
            std::vector<std::string> teammates_vec;
            QString qteammates;
            if (json.contains("teammates") && json["teammates"].isArray()) {
                QJsonArray project_array = json["teammates"].toArray();
                qteammates_vec.reserve(project_array.size());
                for (int i = 0; i < project_array.size(); ++i) {
                    qteammates.push_back(project_array[i].toString());
                    qteammates += " ";
                    qteammates_vec.append(project_array[i].toString());
                    teammates_vec.push_back(project_array[i].toString().toStdString());
                }
            }

//          post_tags
            QVector<QString> qpost_tags_vec;
            std::vector<std::string> post_tags_vec;
            QString qpost_tags;
            if (json.contains("post_tags") && json["post_tags"].isArray()) {
                QJsonArray project_array = json["post_tags"].toArray();
                qpost_tags_vec.reserve(project_array.size());
                for (int i = 0; i < project_array.size(); ++i) {
                    qpost_tags.push_back(project_array[i].toString());
                    qpost_tags += " ";
                    qpost_tags_vec.append(project_array[i].toString());
                    post_tags_vec.push_back(project_array[i].toString().toStdString());
                }
            }

            ui->l_project_name->setText(qproject_name);
            ui->l_team_name->setText(qteam_name);
            ui->l_post_tags->setText(qpost_tags);
            ui->l_teammates->setText(qteammates);
            ui->l_project_description->setText(qproject_description);

//            _context->setTeamNameProjectData(qteam_name.toStdString());
//            _context->setTeammatesProjectData(teammates_vec);
//            _context->setProjectDescriptionProjectData(qproject_description.toStdString());
//            _context->setProjectNameProjectData(qproject_name.toStdString());
//            _context->setPostTagsProjectData(post_tags_vec);

        } else {
            qDebug("Project Error");
        }
    });

}


void ProjectPage::on_pushBackButton_clicked()
{
    this->close();
    emit goToUserPage();
}


void ProjectPage::on_pushRequestToProjectButton_clicked()
{

}

