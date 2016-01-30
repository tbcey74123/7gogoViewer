#include "graphicviewer.h"

#include <QDebug>

#include <QStyle>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>

GraphicViewer::GraphicViewer(QObject *parent) : QObject(parent) {

    init();
}

//Initializatoin
void GraphicViewer::init() {

    scene = new QGraphicsScene;
    view = new QGraphicsView(scene);

    item = NULL;
}

//Getters and Setters
void GraphicViewer::setMaxSize(const QSize size) {
    maxWidth = size.width();
    maxHeight = size.height();
}

//private functions
void GraphicViewer::resize(const QPixmap &map) {

    int width = map.width() >= maxWidth ? maxWidth : map.width();
    int height = map.height() >= maxHeight ? maxHeight : map.height();

    view->resize(width + 30, height);
    view->setSceneRect(map.rect());

}

//public slots
void GraphicViewer::addImage(const QPixmap &map) {
/*
    if(item != NULL)
        scene->removeItem(item);
*/
    scene->clear();

    int width = map.width() >= maxWidth ? maxWidth : map.width();
    QPixmap newMap = map.scaledToWidth(width);
    item = new QGraphicsPixmapItem(newMap);

    scene->addItem(item);

    resize(newMap);
    view->show();

}
