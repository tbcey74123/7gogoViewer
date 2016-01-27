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



    int messageNumber;
    QVBoxLayout *vBox;

public:

    Window *window;

    explicit ContentBox(QWidget *parent = 0);


    void addMessage(MessageBox *messageBox);

    void setWidth(const int &w);

private:
    void init();

public slots:
    void expandHeight(MessageBox *box);

};

#endif // CONTENTBOX_H
