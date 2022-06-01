#ifndef LOOK_FOR_USER_H
#define LOOK_FOR_USER_H

#include <QWidget>
#include "utils.hpp"
#include "general.h"

namespace Ui {
class LookForUser;
}

class LookForUser : public QWidget
{
    Q_OBJECT

public:
    explicit LookForUser(QWidget *parent = nullptr, std::shared_ptr<Context> context = nullptr);
    ~LookForUser();

signals:
    void goToMainUserPage();

private slots:
    void on_pushBackButton_clicked();

private:
    Ui::LookForUser *ui;

    std::shared_ptr<Context> _context;
};

#endif // LOOK_FOR_USER_H
