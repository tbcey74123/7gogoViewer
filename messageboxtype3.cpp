#include "messageboxtype3.h"

#include "window.h"
#include "contentbox.h"

#include "image.h"
#include "imagelabel.h"

#include <QStyle>
#include <QDebug>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

MessageBoxType3::MessageBoxType3(const QJsonValue &value, QWidget *parent) : MessageBoxType3(value.toObject()["posts"].toArray()[0].toObject(), parent){}
MessageBoxType3::MessageBoxType3(const QJsonObject &post, QWidget *parent) : MessageBox(post, parent){

    contentBox = dynamic_cast <ContentBox *>(parent);
    initPost(post);
}

void MessageBoxType3::init(const QJsonValue &value) {

    img = new Image;
    QObject::connect(img, &Image::ImageFinished, this, &MessageBoxType3::ImageInitFinished);

    if(parentWidget() != NULL)
        img->setFixedWidth(parentWidget()->width() - 40);

    QJsonObject post = value.toObject()["posts"].toArray()[0].toObject();
    QJsonArray postBody = post["body"].toArray();

    for(int i = 0; i < postBody.count(); i++) {
        QJsonObject obj = postBody[i].toObject();
        int bodyType = obj["bodyType"].toInt();
        if(bodyType == 3) {
            img->initWithUrl(obj["image"].toString());
        }
    }

    QObject::connect(img->getThumbnail(), &ImageLabel::imagePressed, [=]() {
       contentBox->window->addGraphics(*(img->getOriImg()->pixmap()));
    });
}
void MessageBoxType3::initPost(const QJsonObject &post) {

    img = new Image;
    QObject::connect(img, &Image::ImageFinished, this, &MessageBoxType3::ImageInitFinished);

    if(parentWidget() != NULL)
        img->setFixedWidth(parentWidget()->width() - 40);

    QJsonArray postBody = post["body"].toArray();

    for(int i = 0; i < postBody.count(); i++) {
        QJsonObject obj = postBody[i].toObject();
        int bodyType = obj["bodyType"].toInt();
        if(bodyType == 3) {
            img->initWithUrl(obj["image"].toString());
        }
    }

}

void MessageBoxType3::ImageInitFinished() {

    //img->getThumbnail()->setStyleSheet("margin-left: 200");
    //img->getThumbnail()->move(200, 0);
    layout->addWidget(img->getThumbnail(), 1, 0);
    layout->setAlignment(img->getThumbnail(), Qt::AlignCenter);

    setFixedHeight(sizeHint().height());

    emit boxFinished(this);
}



