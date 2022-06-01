#ifndef PUBLISH_POST_PAGE_H
#define PUBLISH_POST_PAGE_H

#include <QWidget>
#include "utils.hpp"
#include "general.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

namespace Ui {
class PublishPostPage;
}

class PublishPostPage : public QWidget
{
    Q_OBJECT

public:
    explicit PublishPostPage(QWidget *parent = nullptr, std::shared_ptr<Context> context = nullptr);
    ~PublishPostPage();

signals:
    void goToUserPage();

private slots:
    void on_pushSavePublishButton_clicked();

    void on_pushBackButton_clicked();

private:
    Ui::PublishPostPage *ui;

    std::shared_ptr<Context> _context;

    QNetworkAccessManager* publishPostNetworkManager;
};

#endif // PUBLISH_POST_PAGE_H
