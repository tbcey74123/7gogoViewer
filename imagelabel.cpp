#include "imagelabel.h"



#include <QDebug>
#include <QMouseEvent>

ImageLabel::ImageLabel(QWidget *parent) : QLabel(parent) {

}
ImageLabel::ImageLabel(const QByteArray &data, QWidget *parent) : QLabel(parent) {
    QPixmap map;
    map.loadFromData(data);

    setPixmap(map);
    resize(map.size());
}
ImageLabel::ImageLabel(const QPixmap &map, QWidget *parent) : QLabel(parent) {
    setPixmap(map);
    resize(map.size());
}

void ImageLabel::setImage(const QByteArray &data) {


    QPixmap map;
    map.loadFromData(data);

    setPixmap(map);
    resize(map.size());
}

void ImageLabel::setImage(const QPixmap &map) {

    setPixmap(map);
    resize(map.size());
}

void ImageLabel::resizeToWidth(int w) {

    QPixmap map = pixmap()->scaledToWidth(w);
    setImage(map);
}
void ImageLabel::resizeToHeight(int h) {

    QPixmap map = pixmap()->scaledToHeight(h);
    setImage(map);
}



//Event Handling
void ImageLabel::mousePressEvent(QMouseEvent *event) {

    //qDebug() << "x: " + QString::number(event->x()) + ", y: " + QString::number(event->y());
    if(event->x() > 0 && event->x() < pixmap()->width()) {
        qDebug() << "press on the image.";
        emit imagePressed();
    }
}
