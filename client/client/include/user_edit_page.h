#ifndef USER_EDIT_PAGE_H
#define USER_EDIT_PAGE_H

#include <QWidget>

namespace Ui {
class UserEditPage;
}

class UserEditPage : public QWidget
{
    Q_OBJECT

public:
    explicit UserEditPage(QWidget *parent = nullptr);
    ~UserEditPage();

signals:
    void goToUserPage();
    void goToLoginPage();

private slots:
    void on_pushGoToUserPageButton_clicked();

    void on_pushSaveButton_clicked();

    void on_pushAddPhotoButton_clicked();

    void on_pushLogOutButton_clicked();

private:
    Ui::UserEditPage *ui;
};

#endif // USER_EDIT_PAGE_H
