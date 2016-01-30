#include "window.h"
#include "graphicviewer.h"
#include "contentbox.h"

#include "messagebox.h"

#include <QApplication>
#include <QDesktopWidget>

#include <QDebug>
#include <QFile>
#include <QWidget>
#include <QStyle>
#include <QPushButton>
#include <QScrollArea>
#include <QGroupBox>
#include <QVBoxLayout>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QJsonValue>
#include <QJsonDocument>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>


Window::Window(QWidget *parent) : QWidget(parent) {

    init();
}

//Initiate
void Window::init() {

    setFixedSize(Size::DEFAULT_WIDTH, Size::DEFAULT_HEIGHT);

    vBox = new QVBoxLayout;
    vBox->setContentsMargins(5, 5, 5, 5);
    setLayout(vBox);

    initControlPanel();
    initContentBox();
    initGraphicViewer();

    scroll = new QScrollArea;
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll->setWidget(contentBox);

    vBox->addWidget(controlPanel);
    vBox->addWidget(scroll);


}

void Window::initControlPanel() {

    controlPanel = new QGroupBox("Control Panel", this);
    controlPanel->setFixedSize(Size::DEFAULT_WIDTH - vBox->contentsMargins().left() - vBox->contentsMargins().right(), 100); //set the width to the DEFAULT_WIDTH of the window
                                                                                                                             //substracting the left, right margins of the layout.
    QPushButton *button = new QPushButton("press", controlPanel);

    int *test = new int;
    *test = 0;

    QObject::connect(button, &QPushButton::pressed, [=] {

        QJsonValue json[3];
        QString line;

        QFile file("json.txt");
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "File cannot be opened";
        }else {
            while(!file.atEnd()) {
                line = file.readLine();
                //qDebug() << line;
            }
        }
        file.close();
        json[0] = QJsonValue::fromVariant(QJsonDocument::fromJson(line.toUtf8()).toVariant());

        QFile file1("json2.txt");
        if(!file1.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "File cannot be opened";
        }else {
            while(!file1.atEnd()) {
                line = file1.readLine();
                //qDebug() << line;
            }
        }
        file1.close();
        json[1] = QJsonValue::fromVariant(QJsonDocument::fromJson(line.toUtf8()).toVariant());

        QFile file2("json3.txt");
        if(!file2.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "File cannot be opened";
        }else {
            while(!file2.atEnd()) {
                line = file2.readLine();
                //qDebug() << line;
            }
        }
        file2.close();
        json[2] = QJsonValue::fromVariant(QJsonDocument::fromJson(line.toUtf8()).toVariant());

        for(int i = 0; i < 3; i++) {
            //qDebug() << json[i];
            MessageBox *messageBox = MessageBox::fromJson(json[i], contentBox);
            contentBox->addMessage(messageBox);
/*
            QObject::connect(messageBox, &MessageBox::boxFinished, [=]() {
                contentBox->addMessage(messageBox);
            });
*/
        }
/*
        MessageBox *messageBox = MessageBox::fromJson(json, contentBox);
        QObject::connect(messageBox, &MessageBox::boxFinished, [=]() {
            contentBox->addMessage(messageBox);
        });
*/

    });
}

void Window::initContentBox() {
    contentBox = new ContentBox(this);
    contentBox->setFixedWidth(Size::DEFAULT_WIDTH - vBox->contentsMargins().left() - vBox->contentsMargins().right() - style()->pixelMetric(QStyle::PM_ScrollBarExtent));
                                                                                                                       //set the width to the DEFAULT_WIDTH of the window
                                                                                                                       //substracting the left, right margins of the layout,                                                                                                                       //and the width of the scrolling bar.
}
void Window::initGraphicViewer() {
    graphicViewer = new GraphicViewer(this);

    //graphicViewer->setMaxSize(QApplication::desktop()->screenGeometry().size());
    graphicViewer->setMaxSize(QSize(800, 600));
}

//public slots
void Window::addImage(const QPixmap &map) {

    graphicViewer->addImage(map);
}

