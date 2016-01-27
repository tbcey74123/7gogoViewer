#ifndef IMAGELABEL_H
#define IMAGELABEL_H

#include <QLabel>

class ImageLabel : public QLabel {

    Q_OBJECT

public:
    ImageLabel(QWidget *parent = 0);
    ImageLabel(const QByteArray &data, QWidget *parent = 0);
    ImageLabel(const QPixmap &map, QWidget *parent = 0);

    void setImage(const QByteArray &data);
    void setImage(const QPixmap &map);

    void resizeToWidth(int w);
    void resizeToHeight(int h);

protected:
    void mousePressEvent(QMouseEvent *event);

signals:
    void imagePressed();

};

#endif // IMAGELABEL_H
