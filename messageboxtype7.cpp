#include "messageboxtype7.h"

#include "window.h"
#include "contentbox.h"

#include "image.h"
#include "imagelabel.h"

#include <QDebug>
#include <QStyleOption>
#include <QPainter>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

MessageBoxType7::MessageBoxType7(const QJsonValue &value, QWidget *parent) : MessageBoxType7(value.toObject()["posts"].toArray()[0].toObject(), parent){}
MessageBoxType7::MessageBoxType7(const QJsonObject &post, QWidget *parent) : MessageBox(post, parent){

    contentBox = dynamic_cast <ContentBox *>(parent);
    initPost(post);
}

void MessageBoxType7::init(const QJsonValue &value) {

}

void MessageBoxType7::initPost(const QJsonObject &post) {


    QJsonArray postBody = post["body"].toArray();

    nam = new QNetworkAccessManager;
    qDebug() << "tset";
    conn = QObject::connect(nam, &QNetworkAccessManager::finished, this, &MessageBoxType7::ImageDownloadFinished);

    memberText = new QLabel(this);
/*
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::white);
    memberText->setAutoFillBackground(true);
    memberText->setPalette(pal);
*/
    img = new Image;

    if(parentWidget() != NULL) {
        memberText->setFixedWidth(parentWidget()->width() - 40);
        img->setFixedWidth(parentWidget()->width() - 40);
    }

    QString text = "";
    for(int i = 0; i < postBody.count(); i++) {
        QJsonObject obj = postBody[i].toObject();
        int bodyType = obj["bodyType"].toInt();
        if(bodyType == 1)
            text += obj["text"].toString();
        else if(bodyType == 3) {
            nam->get(QNetworkRequest(QUrl(obj["image"].toString())));
        }
    }

    memberText->setText(text);
    memberText->setWordWrap(true);
    memberText->setMinimumHeight(memberText->sizeHint().height());

    layout->addWidget(memberText, 2, 0);


}

void MessageBoxType7::ImageDownloadFinished(QNetworkReply *reply) {

    QObject::disconnect(conn);
/*
    QPixmap map;
    map.loadFromData(reply->readAll());

    img->setPixmap(map);
    img->resize(map.size());
*/
    img->initWithData(reply->readAll());

    //img->getThumbnail()->setStyleSheet("margin-left: 200");
    layout->addWidget(img->getThumbnail(), 1, 0);
    layout->setAlignment(img->getThumbnail(), Qt::AlignCenter);

    setFixedHeight(sizeHint().height());

    emit boxFinished(this);
}



