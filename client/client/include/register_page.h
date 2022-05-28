#ifndef REGISTER_PAGE_H
#define REGISTER_PAGE_H

#include <QWidget>

namespace Ui {
class RegisterPage;
}

class RegisterPage : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterPage(QWidget *parent = nullptr);
    ~RegisterPage();

signals:
    void goToLoginPage();

private slots:
    void on_pushRegisterButton_clicked();

    void on_pushGoToLoginButton_clicked();

private:
    Ui::RegisterPage *ui;
};

#endif // REGISTER_PAGE_H
