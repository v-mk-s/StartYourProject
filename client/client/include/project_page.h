#ifndef PROJECT_PAGE_H
#define PROJECT_PAGE_H

#include <QWidget>

namespace Ui {
class ProjectPage;
}

class ProjectPage : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectPage(QWidget *parent = nullptr);
    ~ProjectPage();

private slots:
    void on_pushSearchButton_clicked();

    void on_checkIsUserBox_stateChanged(int arg1);

private:
    Ui::ProjectPage *ui;

    enum SearchValue { project, user };

    SearchValue search;
};

#endif // PROJECT_PAGE_H
