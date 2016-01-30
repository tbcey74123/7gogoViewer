#ifndef CONTENTBOX_H
#define CONTENTBOX_H

#include <QWidget>
#include <QDebug>

class Window;
class QVBoxLayout;
class MessageBox;
class QNetworkAccessManager;

class ContentBox : public QWidget {

    Q_OBJECT


    Window *window;

    int messageNumber;
    QVBoxLayout *vBox;

public:


    explicit ContentBox(QWidget *parent = 0);


    void addMessage(MessageBox *messageBox);

    Window *getWindow();
    void setWidth(const int &w);

private:
    void init();

public slots:
    void expandHeight(MessageBox *box);
    void test();

};

#endif // CONTENTBOX_H
