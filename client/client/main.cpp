#include "login_page.h"
#include "project_page.h"
#include "application_core.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ApplicationCore goSyp;

    LoginPage* login_w = goSyp.getLoginPage();
    login_w->show();
    return a.exec();
}
