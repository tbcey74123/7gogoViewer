#include "messageboxtype5.h"
#include <messagebox.h>

#include <QDebug>
#include <QPalette>

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#include <QTimer>

MessageBoxType5::MessageBoxType5(const QJsonValue &value, QWidget *parent) : MessageBoxType5(value.toObject()["posts"].toArray()[0].toObject(), parent){}
MessageBoxType5::MessageBoxType5(const QJsonObject &post, QWidget *parent) : MessageBox(post, parent){


    initPost(post);
}

void MessageBoxType5::init(const QJsonValue &value) {

    QJsonObject post = value.toObject()["posts"].toArray()[0].toObject();

    QJsonArray postBody = post["body"].toArray();
/*
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
*/
}

void MessageBoxType5::initPost(const QJsonObject &post) {
    QJsonObject postBody = post["body"].toArray()[0].toObject();
    initRetalkFrom(postBody["post"].toObject()["talkName"].toString());

    retalkContent = MessageBox::fromJson(postBody["post"].toObject(), parentWidget());

    QObject::connect(retalkContent, &MessageBox::boxFinished, [=]() {
        layout->addWidget(retalkContent, 2, 0);

        setFixedHeight(sizeHint().height());

        emit boxFinished(this);
    });

}

void MessageBoxType5::initRetalkFrom(QString src) {

    QString s = "Retalk from 「" + src + "」";

    retalkFrom = new QLabel(s, this);
    layout->addWidget(retalkFrom, 1, 0);

}
