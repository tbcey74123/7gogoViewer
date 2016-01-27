#include "messagebox.h"
#include "contentbox.h"
#include "messageboxtype1.h"
#include "messageboxtype2.h"
#include "messageboxtype3.h"
#include "messageboxtype4.h"
#include "messageboxtype5.h"
#include "messageboxtype6.h"
#include "messageboxtype7.h"
#include "messageboxtype8.h"

#include <QDebug>
#include <QFont>
#include <QPalette>
#include <QGridLayout>
#include <QLabel>
#include <QPlainTextEdit>
#include <QTextBrowser>
#include <QPixmap>
#include <QStyleOption>
#include <QPainter>

#include <QNetworkReply>

#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include <QThread>


MessageBox::MessageBox(QWidget *parent) : QWidget(parent){
};

MessageBox::MessageBox(const QJsonValue &value, QWidget *parent) : MessageBox(value, -1, parent){};
MessageBox::MessageBox(const QJsonObject &post, QWidget *parent) : MessageBox(post, -1, parent){};

MessageBox::MessageBox(const QJsonValue &value, const int &messageNum, QWidget *parent) : QWidget(parent) {

    init(value);
}
MessageBox::MessageBox(const QJsonObject &post, const int &messageNum, QWidget *parent) : QWidget(parent) {

    initPost(post);
}

//Basis for initialization
void MessageBox::init(const QJsonValue &value) {
/*
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::gray);
    setAutoFillBackground(true);
    setPalette(pal);
*/
    setStyleSheet("border: 1px solid red;");

    layout = new QGridLayout;
    this->setLayout(layout);

    initMemberName(value.toObject()["posts"].toArray()[0].toObject()["sendUserName"].toString());
}

void MessageBox::initPost(const QJsonObject &post) {
/*
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::gray);
    setAutoFillBackground(true);
    setPalette(pal);
*/
    setStyleSheet("MessageBox {"
                  "border: 1px solid red;"
                  "}");

    layout = new QGridLayout;
    this->setLayout(layout);

    initMemberName(post["sendUserName"].toString());
}

void MessageBox::initMemberName(const QString &name) {

    QFont nameFont;
    nameFont.setBold(true);

    //memberName = new QLabel(name + QString::number(messageNum), this);
    memberName = new QLabel(name, this);
    memberName->setFont(nameFont);

    layout->addWidget(memberName, 0, 0);
}

void MessageBox::paintEvent(QPaintEvent *) {
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

//Getters and Setters
void MessageBox::setMessageNum(const int messageNum) { this->messageNum = messageNum; }
int MessageBox::getMessageNum() { return messageNum; }

//Public Static Function
int MessageBox::determineType(const QJsonObject &post) {

    return post["postType"].toInt();

}

MessageBox *MessageBox::fromJson(const QJsonValue &value, QWidget *parent) {

    int type = MessageBox::determineType(value.toObject()["posts"].toArray()[0].toObject());
    if(type == 1)
        return new MessageBoxType1(value, parent);
    else if(type == 2)
        return new MessageBoxType2(value, parent);
    else if(type == 3)
        return new MessageBoxType3(value, parent);
    else if(type == 4)
        return new MessageBoxType4(value, parent);
    else if(type == 5)
        return new MessageBoxType5(value, parent);
    else if(type == 6)
        return new MessageBoxType6(value, parent);
    else if(type == 7)
        return new MessageBoxType7(value, parent);
    else if(type == 8)
        return new MessageBoxType8(value, parent);
    else {
        qDebug() << "Unknown Type: " + QString::number(type);
        return new MessageBox(parent);
    }
}
MessageBox *MessageBox::fromJson(const QJsonObject &post, QWidget *parent) {

    int type = MessageBox::determineType(post);
    if(type == 1)
        return new MessageBoxType1(post, parent);
    else if(type == 2)
        return new MessageBoxType2(post, parent);
    else if(type == 3)
        return new MessageBoxType3(post, parent);
    else if(type == 4)
        return new MessageBoxType4(post, parent);
    else if(type == 5)
        return new MessageBoxType5(post, parent);
    else if(type == 6)
        return new MessageBoxType6(post, parent);
    else if(type == 7)
        return new MessageBoxType7(post, parent);
    else if(type == 8)
        return new MessageBoxType8(post, parent);
    else {
        qDebug() << "Unknown Type: " + QString::number(type);
        return new MessageBox(parent);
    }
}

