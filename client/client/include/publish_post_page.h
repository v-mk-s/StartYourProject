#ifndef PUBLISH_POST_PAGE_H
#define PUBLISH_POST_PAGE_H

#include <QWidget>

namespace Ui {
class PublishPostPage;
}

class PublishPostPage : public QWidget
{
    Q_OBJECT

public:
    explicit PublishPostPage(QWidget *parent = nullptr);
    ~PublishPostPage();

private slots:
    void on_pushSavePublishButton_clicked();

private:
    Ui::PublishPostPage *ui;
};

#endif // PUBLISH_POST_PAGE_H
