#include "image.h"
#include "imagelabel.h"

#include <QDebug>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>


Image::Image(QWidget *parent) : QWidget(parent) {
    thumbnail = new ImageLabel(parent);
    oriImg = new ImageLabel(this);
    nam = new QNetworkAccessManager;

/*
    scene = new QGraphicsScene;
    view = new QGraphicsView(scene);
    QObject::connect(thumbnail, &ImageLabel::imagePressed, [=] {
       item = new QGraphicsPixmapItem(*(oriImg->pixmap()));
       scene->addItem(item);
       view->show();
    });
*/
}
Image::Image(const QByteArray &data, QWidget *parent) : QWidget(parent) {

    thumbnail = new ImageLabel(data, parent);
    if(thumbnail->pixmap()->size().width() >= Image::thumnnailMaxWidth)
        thumbnail->resizeToWidth(300);

    //thumbnail->resizeToWidth();

    oriImg = new ImageLabel(data, this);
}
Image::Image(const QPixmap &map, QWidget *parent) : QWidget(parent) {
    thumbnail = new ImageLabel(map, parent);
    if(thumbnail->pixmap()->size().width() >= Image::thumnnailMaxWidth)
        thumbnail->resizeToWidth(300);

    //thumbnail->resizeToWidth();

    oriImg = new ImageLabel(map, this);
}

void Image::initWithData(const QByteArray &data) {

    thumbnail->setImage(data);
    if(thumbnail->pixmap()->size().width() >= Image::thumnnailMaxWidth)
        thumbnail->resizeToWidth(300);

    oriImg->setImage(data);

}
void Image::initWithMap(const QPixmap &map) {
    thumbnail->setImage(map);
    if(thumbnail->pixmap()->size().width() >= Image::thumnnailMaxWidth)
        thumbnail->resizeToWidth(300);

    //thumbnail->resizeToWidth();

    oriImg->setImage(map);
}
void Image::initWithUrl(QString url) {
    conn = QObject::connect(nam, &QNetworkAccessManager::finished, this, &Image::ImageDownloadFinished);

    nam->get(QNetworkRequest(QUrl(url)));

}

//Getters and Setters
ImageLabel *Image::getThumbnail() { return thumbnail; }
ImageLabel *Image::getOriImg() { return oriImg; }


//public slots
void Image::ImageDownloadFinished(QNetworkReply *reply) {

    QObject::disconnect(conn);

/*
    QPixmap map;
    map.loadFromData(reply->readAll());

    img->setPixmap(map);
    img->resize(map.size());
*/
    initWithData(reply->readAll());

    emit ImageFinished();
}
