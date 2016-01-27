#include "messageboxtype8.h"
#include "messagebox.h"
#include "image.h"
#include "imagelabel.h"

#include <QDebug>
#include <QPalette>

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#include <QTimer>

MessageBoxType8::MessageBoxType8(const QJsonValue &value, QWidget *parent) : MessageBoxType8(value.toObject()["posts"].toArray()[0].toObject(), parent){}
MessageBoxType8::MessageBoxType8(const QJsonObject &post, QWidget *parent) : MessageBox(post, parent){

    initPost(post);
}

void MessageBoxType8::init(const QJsonValue &value) {
/*
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
        emit boxFinished();
    });
    timer->start(100);
*/
}

void MessageBoxType8::initPost(const QJsonObject &post) {

    QJsonArray postBody = post["body"].toArray();

    img = new Image;
    QObject::connect(img, &Image::ImageFinished, this, &MessageBoxType8::ImageInitFinished);

    video = new QLabel("Video settings are not finishied yet", this);
    video->setStyleSheet("color: red;");

    memberText = new QLabel(this);

    if(parentWidget() != NULL) {
        img->setFixedWidth(parentWidget()->width() - 40);
        memberText->setFixedWidth(parentWidget()->width() - 40);
    }

    QPalette pal;
    pal.setColor(QPalette::Background, Qt::white);
    video->setAutoFillBackground(true);
    video->setPalette(pal);
    memberText->setAutoFillBackground(true);
    memberText->setPalette(pal);

    QString thumbnailUrl = postBody[0].toObject()["thumbnailUrl"].toString();
    QString videoUrl = postBody[0].toObject()["movieUrlHq"].toString();
    img->initWithUrl(thumbnailUrl);

    QString text = "";
    for(int i = 1; i < postBody.count(); i++) {
        QJsonObject obj = postBody[i].toObject();
        int bodyType = obj["bodyType"].toInt();
        if(bodyType == 1)
            text += obj["text"].toString();
    }
    memberText->setText(text);
    memberText->setWordWrap(true);
    memberText->setMinimumHeight(memberText->sizeHint().height());

    layout->addWidget(video, 2, 0);
    layout->addWidget(memberText, 3, 0);

}

void MessageBoxType8::ImageInitFinished() {

    //img->getThumbnail()->setStyleSheet("margin-left: 200");
    layout->addWidget(img->getThumbnail(), 1, 0);
    layout->setAlignment(img->getThumbnail(), Qt::AlignCenter);

    setFixedHeight(sizeHint().height());

    emit boxFinished(this);
}

