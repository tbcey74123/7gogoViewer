#include "messageboxtype1.h"
#include <messagebox.h>

#include <QDebug>
#include <QPalette>

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#include <QTimer>

MessageBoxType1::MessageBoxType1(const QJsonValue &value, QWidget *parent) : MessageBoxType1(value.toObject()["posts"].toArray()[0].toObject(), parent){}
MessageBoxType1::MessageBoxType1(const QJsonObject &post, QWidget *parent) : MessageBox(post, parent){

    initPost(post);
}


void MessageBoxType1::init(const QJsonValue &value) {

    QJsonObject post = value.toObject()["posts"].toArray()[0].toObject();

    memberText = new QLabel(this);

    if(parentWidget() != NULL)
        memberText->setFixedWidth(parentWidget()->width() - 40);

    QPalette pal;
    pal.setColor(QPalette::Background, Qt::white);
    memberText->setAutoFillBackground(true);
    memberText->setPalette(pal);

    QJsonArray postBody = post["body"].toArray();

    QString text = "";
    for(int i = 0; i < postBody.count(); i++) {
        QJsonObject obj = postBody[i].toObject();
        int bodyType = obj["bodyType"].toInt();
        if(bodyType == 1)
            text += obj["text"].toString();
    }
    memberText->setText(text);
    memberText->setWordWrap(true);
    memberText->setMinimumHeight(memberText->sizeHint().height());

    layout->addWidget(memberText, 1, 0);

    QTimer *timer = new QTimer;
    QObject::connect(timer, &QTimer::timeout, [=] {
        timer->stop();
        timer->deleteLater();
        emit boxFinished(this);
    });
    timer->start(100);
}

void MessageBoxType1::initPost(const QJsonObject &post) {

    memberText = new QLabel(this);

    if(parentWidget() != NULL)
        memberText->setFixedWidth(parentWidget()->width() - 40);

    QPalette pal;
    pal.setColor(QPalette::Background, Qt::white);
    memberText->setAutoFillBackground(true);
    memberText->setPalette(pal);

    QJsonArray postBody = post["body"].toArray();

    QString text = "";
    for(int i = 0; i < postBody.count(); i++) {
        QJsonObject obj = postBody[i].toObject();
        int bodyType = obj["bodyType"].toInt();
        if(bodyType == 1)
            text += obj["text"].toString();
    }
    memberText->setText(text);
    memberText->setWordWrap(true);
    memberText->setMinimumHeight(memberText->sizeHint().height());

    layout->addWidget(memberText, 1, 0);

    setFixedHeight(sizeHint().height());

    QTimer *timer = new QTimer;
    QObject::connect(timer, &QTimer::timeout, [=] {
        timer->stop();
        timer->deleteLater();
        emit boxFinished(this);
    });
    timer->start(100);

}
