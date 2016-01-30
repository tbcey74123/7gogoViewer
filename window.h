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
class QPixmap;

class GraphicViewer;

class Window : public QWidget {

    Q_OBJECT

    enum Size {DEFAULT_WIDTH = 800, DEFAULT_HEIGHT = 600};

    QGroupBox *controlPanel;
    QScrollArea *scroll;
    ContentBox *contentBox;
    QVBoxLayout *vBox;

    GraphicViewer *graphicViewer;

public:
    explicit Window(QWidget *parent = 0);

private:
    void init();
    void initControlPanel();
    void initContentBox();
    void initGraphicViewer();


public slots:
    void addImage(const QPixmap &map);
};

#endif // WINDOW_H
