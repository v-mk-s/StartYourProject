#include "user_page.h"
#include "ui_user_page.h"
#include "user_edit_page.h"
#include "project_page.h"
#include "publish_post_page.h"
#include "look_for_user.h"

#include <QMessageBox>
#include <QJsonObject>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonArray>
#include <QString>
#include <vector>


UserPage::UserPage(QWidget *parent, std::shared_ptr<Context> context) :
    QWidget(parent)
    , ui(new Ui::UserPage)
    , userNetworkManager(new QNetworkAccessManager)
    , _context(context)
{
    ui->setupUi(this);

    QWidget* user_edit_widget = nullptr;
    user_edit_ui = new UserEditPage(user_edit_widget, _context);
    connect(user_edit_ui, &UserEditPage::goToUserPage, this, &UserPage::show);

    QWidget* publish_post_widget = nullptr;
    publish_post_ui = new PublishPostPage(publish_post_widget, _context);
    connect(publish_post_ui, &PublishPostPage::goToUserPage, this, &PublishPostPage::show);

    QWidget* project_widget = nullptr;
    project_ui = new ProjectPage(project_widget, _context);
    connect(project_ui, &ProjectPage::goToUserPage, this, &ProjectPage::show);

    QWidget* look_for_user_widget = nullptr;
    look_for_user_ui = new LookForUser(look_for_user_widget, _context);
    connect(look_for_user_ui, &LookForUser::goToMainUserPage, this, &LookForUser::show);


    // load data
    QJsonObject param;
    param.insert("username",  QString::fromStdString(_context->getUserData().username));

    QJsonDocument doc(param);
    QString strJson(doc.toJson(QJsonDocument::Compact));

    QNetworkRequest request;
    request.setUrl(QUrl(QString::fromStdString(std::string(URL) + GET_PROFILE_URL)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setHeader(QNetworkRequest::ContentLengthHeader, strJson.length());

//        std::cout << strJson.length() << std::endl;

    auto responce = userNetworkManager->post(request,
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

            QString qusername = json["username"].toString();
            QString qemail = json["email"].toString();
            QString qname = json["name"].toString();
            QString qsurname = json["sur_name"].toString();

            QVector<QString> qprojects_vec;
            std::vector<std::string> projects_vec;
            QString qprojects;
            if (json.contains("projects") && json["projects"].isArray()) {
                QJsonArray project_array = json["projects"].toArray();
                qprojects_vec.reserve(project_array.size());
                for (int i = 0; i < project_array.size(); ++i) {
                    qprojects.push_back(project_array[i].toString());
                    qprojects += " ";
                    qprojects_vec.append(project_array[i].toString());
                    projects_vec.push_back(project_array[i].toString().toStdString());
                }
            }

            QString quser_description = json["user_discription"].toString();

            ui->l_username->setText(qusername);
            ui->l_email->setText(qemail);
            ui->l_name->setText(qname);
            ui->l_surname->setText(qsurname);         
            ui->l_projects->setText(qprojects);
            ui->l_user_description->setText(quser_description);

            _context->setUsernameUserData(qusername.toStdString());
            _context->setNameUserData(qname.toStdString());
            _context->setEmailUserData(qemail.toStdString());
            _context->setSurnameUserData(qsurname.toStdString());
            _context->setProjectsUserData(projects_vec);
            _context->setUserDescriptionUserData(quser_description.toStdString());

        } else {
            qDebug("User Error");
        }
    });
}

UserPage::~UserPage()
{
    delete ui;
}

void UserPage::on_pushSearchProjectButton_clicked()
{
    this->close();
    project_ui->show();
}


void UserPage::on_pushBackButton_clicked()
{

}


void UserPage::on_pushLogOutButton_clicked()
{
    this->close();
    emit LogOut();
}


void UserPage::on_pushUserEditButton_clicked()
{
    this->close();
    user_edit_ui->show();
}


void UserPage::on_pushPublishPostButton_clicked()
{
    this->close();
    publish_post_ui->show();
}



void UserPage::on_pushSearchUserButton_clicked()
{
    this->close();
    look_for_user_ui->show();
}

