#ifndef USER_PAGE_H
#define USER_PAGE_H

#include <QWidget>

namespace Ui {
class UserPage;
}

class UserPage : public QWidget
{
    Q_OBJECT

public:
    explicit UserPage(QWidget *parent = nullptr);
    ~UserPage();

signals:
    void goToLoginPage();
    void goToProjectPage();


private slots:
    void on_pushSearchButton_clicked();

    void on_pushRequestToProjectButton_clicked();

    void on_pushBackButton_clicked();

    void on_pushLogOutButton_clicked();

    void on_pushProject1DelButton_clicked();

private:
    Ui::UserPage *ui;
};

#endif // USER_PAGE_H
