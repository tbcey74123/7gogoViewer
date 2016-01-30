#ifndef GRAPHICVIEWER_H
#define GRAPHICVIEWER_H

#include <QObject>

class QGraphicsScene;
class QGraphicsView;
class QGraphicsPixmapItem;
class QPixmap;

class GraphicViewer : public QObject
{
    Q_OBJECT

    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsPixmapItem *item;

    int maxWidth, maxHeight;

public:
    explicit GraphicViewer(QObject *parent = 0);

    void setMaxSize(const QSize size);

private:
    void init();

    void resize(const QPixmap &map);

signals:

public slots:
    void addImage(const QPixmap &map);

};

#endif // GRAPHICVIEWER_H
