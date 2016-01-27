#include <QApplication>

#include "window.h"
#include "messagebox.h"

#include <QWidget>
#include <QScrollBar>
#include <QDebug>
#include <QLabel>
#include <QPalette>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QNetworkAccessManager>
#include <QNetworkReply>

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QMediaContent>
#include <QMediaResource>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    Window *window = new Window;
    window->show();

/*
    QWidget *window = new QWidget;
    window->setFixedSize(800, 600);

    QMediaResource src(QUrl::fromLocalFile("H:/tttt.mp4"));

    QMediaPlayer *player = new QMediaPlayer;
    QObject::connect(player, &QMediaPlayer::positionChanged, [=](qint64 pos) {
       qDebug() << pos;
    });
    player->setMedia(QUrl("https://video.twimg.com/ext_tw_video/687574993945821184/pu/vid/1280x720/OoHPevEVUe5Z35jY.mp4"));
    player->setVolume(50);


    QMediaPlaylist *playlist = new QMediaPlaylist;
    playlist->addMedia(QUrl::fromLocalFile("H:/tttt.mp4"));
    player->setPlaylist(playlist);

    playlist->next();


    QVideoWidget *videoWidget = new QVideoWidget(window);
    videoWidget->setGeometry(0, 0, 400, 300);
    player->setVideoOutput(videoWidget);
    //videoWidget->show();

    QScrollBar *bar = new QScrollBar(Qt::Horizontal, window);
    bar->move(0, 400);
    bar->setFixedWidth(400);
    QObject::connect(bar, &QScrollBar::valueChanged, [=](int value) {
        double percentage = value / 100.f;
        qint64 pos = player->duration() * percentage;
        player->setPosition(pos);
    });


    //qDebug() << player->media().canonicalResource().resolution();
    window->show();
    player->play();
*/
    return app.exec();
}
