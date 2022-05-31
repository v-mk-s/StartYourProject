#include "look_for_user.h"
#include "ui_look_for_user.h"

LookForUser::LookForUser(QWidget *parent, std::shared_ptr<Context> context) :
    QWidget(parent)
    , ui(new Ui::LookForUser)
    , _context(context)
{
    ui->setupUi(this);
}

LookForUser::~LookForUser()
{
    delete ui;
}

void LookForUser::on_pushBackButton_clicked()
{
    this->close();
    emit goToMainUserPage();
}

