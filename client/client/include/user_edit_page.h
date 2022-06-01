#ifndef USER_EDIT_PAGE_H
#define USER_EDIT_PAGE_H

#include <QWidget>
#include "utils.hpp"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

#include "general.h"

namespace Ui {
class UserEditPage;
}

class UserEditPage : public QWidget
{
    Q_OBJECT

public:
    explicit UserEditPage(QWidget *parent = nullptr, std::shared_ptr<Context> context = nullptr);
    ~UserEditPage();

signals:
    void goToUserPage();
    void goToLoginPage();
    void refreshData();

private slots:
    void on_pushGoToUserPageButton_clicked();

    void on_pushSaveButton_clicked();

    void on_pushAddPhotoButton_clicked();

    void on_pushLogOutButton_clicked();

private:
    Ui::UserEditPage *ui;

    std::shared_ptr<Context> _context;

    QNetworkAccessManager* userEditNetworkManager;
};

#endif // USER_EDIT_PAGE_H
