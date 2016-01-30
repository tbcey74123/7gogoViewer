#include "window.h"
#include "contentbox.h"
#include "messagebox.h"

#include <QDebug>
#include <QPalette>
#include <QVBoxLayout>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>


ContentBox::ContentBox(QWidget *parent) : QWidget(parent) {

    window = dynamic_cast <Window *>(parent);
    init();
}

//Init
void ContentBox::init() {

    messageNumber = 0;
    vBox = new QVBoxLayout;
    setLayout(vBox);
    setFixedHeight(vBox->spacing());
}

//Public Funtion
void ContentBox::addMessage(MessageBox *messageBox) {

    QObject::connect(messageBox, &MessageBox::boxFinished, this, &ContentBox::expandHeight);
    messageBox->setVisible(false);
    vBox->addWidget(messageBox);
    messageNumber++;
}

//Getters and Setters
Window *ContentBox::getWindow() { return window; }
void ContentBox::setWidth(const int &w) {

    setFixedWidth(w);
}

//public slots
void ContentBox::expandHeight(MessageBox *box) {
    box->setVisible(true);
    setFixedHeight(height() + box->size().height() + vBox->spacing());

}

void ContentBox::test() {
    qDebug() << "test";
}


