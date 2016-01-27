#include "messageboxtype2.h"

#include "window.h"
#include "contentbox.h"

#include "image.h"
#include "imagelabel.h"

#include <QDebug>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

MessageBoxType2::MessageBoxType2(const QJsonValue &value, QWidget *parent) : MessageBoxType2(value.toObject()["posts"].toArray()[0].toObject(), parent){}
MessageBoxType2::MessageBoxType2(const QJsonObject &post, QWidget *parent) : MessageBox(post, parent){

    contentBox = dynamic_cast <ContentBox *>(parent);
    initPost(post);
}

void MessageBoxType2::init(const QJsonValue &value) {

    img = new Image;
    QObject::connect(img, &Image::ImageFinished, this, &MessageBoxType2::ImageInitFinished);

    if(parentWidget() != NULL)
        img->setFixedWidth(parentWidget()->width() - 40);

    QJsonObject post = value.toObject()["posts"].toArray()[0].toObject();
    QJsonArray postBody = post["body"].toArray();

    for(int i = 0; i < postBody.count(); i++) {
        QJsonObject obj = postBody[i].toObject();
        int bodyType = obj["bodyType"].toInt();
        if(bodyType == 2) {
            img->initWithUrl(obj["image"].toString());
        }
    }
/*
    QObject::connect(img->getThumbNail(), &ImageLabel::imagePressed, [=]() {
       contentBox->window->addGraphics(*(img->getOriImg()->pixmap()));
    });
*/
}

void MessageBoxType2::initPost(const QJsonObject &post) {

    img = new Image;
    QObject::connect(img, &Image::ImageFinished, this, &MessageBoxType2::ImageInitFinished);

    if(parentWidget() != NULL)
        img->setFixedWidth(parentWidget()->width() - 40);

    QJsonArray postBody = post["body"].toArray();

    for(int i = 0; i < postBody.count(); i++) {
        QJsonObject obj = postBody[i].toObject();
        int bodyType = obj["bodyType"].toInt();
        if(bodyType == 2) {
            img->initWithUrl(obj["image"].toString());
        }
    }

}

void MessageBoxType2::ImageInitFinished() {

    layout->addWidget(img->getThumbnail(), 1, 0);

    setFixedHeight(sizeHint().height());

    emit boxFinished(this);
}

