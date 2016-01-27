#include "messageboxtype4.h"

#include "messagebox.h"

#include <QDebug>
#include <QLabel>
#include <QPalette>

#include <QTimer>

#include <QJsonObject>
#include <QJsonArray>

MessageBoxType4::MessageBoxType4(const QJsonValue &value, QWidget *parent) : MessageBoxType4(value.toObject()["posts"].toArray()[0].toObject(), parent){}
MessageBoxType4::MessageBoxType4(const QJsonObject &post, QWidget *parent) : MessageBox(post, parent) {

    initPost(post);
}

void MessageBoxType4::init(const QJsonValue &value) {

    QPalette pal;
    pal.setColor(QPalette::Background, Qt::white);

    QFont nameFont;
    nameFont.setBold(true);

    QString offsetStyleSheet = "margin-left: " + QString::number(MessageBoxType4::commentOffset) + ";";

    userName = new QLabel(this);
    userName->setFont(nameFont);
    userName->setStyleSheet(offsetStyleSheet + "color: gray;");

    memberText = new QLabel(this);
    memberText->setAutoFillBackground(true);
    memberText->setPalette(pal);

    commentText = new QLabel(this);
    commentText->setAutoFillBackground(true);
    //commentText->setPalette(pal);
    commentText->setStyleSheet(offsetStyleSheet + "background-color: white;"
                                                  "color: gray");

    if(parentWidget() != NULL) {
        memberText->setFixedWidth(parentWidget()->width() - 40);
        commentText->setFixedWidth(parentWidget()->width() - 40 - MessageBoxType4::commentOffset);
    }

    QJsonObject post = value.toObject()["posts"].toArray()[0].toObject();
    QJsonArray postBody = post["body"].toArray();

    QString text = "";
    QString comment = "";
    for(int i = 0; i < postBody.count(); i++) {
        QJsonObject obj = postBody[i].toObject();
        int bodyType = obj["bodyType"].toInt();
        if(bodyType == 1)
            text += obj["text"].toString();
        else if(bodyType == 4) {
            QJsonObject commentJson = obj["comment"] .toObject();

            userName->setText(commentJson["sendUserName"].toString());
            commentText->setText(commentJson["text"].toString());
            commentText->setWordWrap(true);
            commentText->setMinimumHeight(commentText->sizeHint().height());
        }

    }
    memberText->setText(text);
    memberText->setWordWrap(true);
    memberText->setMinimumHeight(memberText->sizeHint().height());

    layout->addWidget(memberText, 1, 0);
    layout->addWidget(userName, 2, 0);
    layout->addWidget(commentText, 3, 0);

    QTimer *timer = new QTimer;
    QObject::connect(timer, &QTimer::timeout, [=] {
        timer->stop();
        timer->deleteLater();
        emit boxFinished(this);
    });
    timer->start(100);

}
void MessageBoxType4::initPost(const QJsonObject &post) {
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::white);

    QFont nameFont;
    nameFont.setBold(true);

    QString offsetStyleSheet = "margin-left: " + QString::number(MessageBoxType4::commentOffset) + ";";

    userName = new QLabel(this);
    userName->setFont(nameFont);
    userName->setStyleSheet(offsetStyleSheet + "color: gray;");

    memberText = new QLabel(this);
    memberText->setAutoFillBackground(true);
    memberText->setPalette(pal);

    commentText = new QLabel(this);
    commentText->setAutoFillBackground(true);
    //commentText->setPalette(pal);
    commentText->setStyleSheet(offsetStyleSheet + "background-color: white;"
                                                  "color: gray");

    if(parentWidget() != NULL) {
        memberText->setFixedWidth(parentWidget()->width() - 40);
        commentText->setFixedWidth(parentWidget()->width() - 40 - MessageBoxType4::commentOffset);
    }

    QJsonArray postBody = post["body"].toArray();

    QString text = "";
    QString comment = "";
    for(int i = 0; i < postBody.count(); i++) {
        QJsonObject obj = postBody[i].toObject();
        int bodyType = obj["bodyType"].toInt();
        if(bodyType == 1)
            text += obj["text"].toString();
        else if(bodyType == 4) {
            QJsonObject commentJson = obj["comment"] .toObject();

            userName->setText(commentJson["sendUserName"].toString());
            commentText->setText(commentJson["text"].toString());
            commentText->setWordWrap(true);
            commentText->setMinimumHeight(commentText->sizeHint().height());
        }

    }
    memberText->setText(text);
    memberText->setWordWrap(true);
    memberText->setMinimumHeight(memberText->sizeHint().height());

    layout->addWidget(memberText, 1, 0);
    layout->addWidget(userName, 2, 0);
    layout->addWidget(commentText, 3, 0);

    setFixedHeight(sizeHint().height());

    QTimer *timer = new QTimer;
    QObject::connect(timer, &QTimer::timeout, [=] {
        timer->stop();
        timer->deleteLater();
        emit boxFinished(this);
    });
    timer->start(100);


}
