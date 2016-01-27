#ifndef IMAGE_H
#define IMAGE_H

#include <QWidget>

class ImageLabel;
class QGraphicsScene;
class QGraphicsView;
class QGraphicsPixmapItem;

class QNetworkAccessManager;
class QNetworkReply;

class Image : public QWidget {

    Q_OBJECT

    enum {thumnnailMaxWidth = 300};

    ImageLabel *thumbnail, *oriImg;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsPixmapItem *item;

    QNetworkAccessManager *nam;
    QMetaObject::Connection conn;

public:
    explicit Image(QWidget *parent = 0);
    explicit Image(const QByteArray &data, QWidget *parent = 0);
    explicit Image(const QPixmap &map, QWidget *parent = 0);

    void initWithData(const QByteArray &data);
    void initWithMap(const QPixmap &map);
    void initWithUrl(QString url);

    ImageLabel *getThumbnail();
    ImageLabel *getOriImg();


signals:
    void ImageFinished();
public slots:
    void ImageDownloadFinished(QNetworkReply *reply);

};

#endif // IMAGE_H
