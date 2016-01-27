#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QGroupBox;
class QVBoxLayout;
class ContentBox;
class QScrollArea;

class QNetworkAccessManager;

class QGraphicsScene;
class QGraphicsView;
class QGraphicsPixmapItem;

class Window : public QWidget {

    Q_OBJECT

    enum Size {DEFAULT_WIDTH = 800, DEFAULT_HEIGHT = 600};

    QGroupBox *controlPanel;
    QScrollArea *scroll;
    ContentBox *contentBox;
    QVBoxLayout *vBox;

    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsPixmapItem *item;



public:
    explicit Window(QWidget *parent = 0);

    void addGraphics(const QPixmap &map);

    void test();

private:
    void init();
    void initControlPanel();
    void initContentBox();

};

#endif // WINDOW_H
