#ifndef PROJECT_PAGE_H
#define PROJECT_PAGE_H

#include <QWidget>
#include "utils.hpp"
#include "general.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

namespace Ui {
class ProjectPage;
}

class ProjectPage : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectPage(QWidget *parent = nullptr, std::shared_ptr<Context> context = nullptr);
    ~ProjectPage();

signals:
    void goToUserPage();

private slots:
    void on_pushSearchButton_clicked();

    void on_pushBackButton_clicked();

    void on_pushRequestToProjectButton_clicked();

private:
    Ui::ProjectPage *ui;

    std::shared_ptr<Context> _context;

    QNetworkAccessManager* projectNetworkManager;
};

#endif // PROJECT_PAGE_H
