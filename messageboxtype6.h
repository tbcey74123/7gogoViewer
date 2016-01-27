#ifndef MESSAGEBOXTYPE6_H
#define MESSAGEBOXTYPE6_H

#include "messagebox.h"

class QWidget;
class QLabel;

class Image;

class QJsonValue;
class QJsonObject;

class MessageBoxType6 : public MessageBox {

    Q_OBJECT

    Image *img;
    QLabel *video;


public:
    MessageBoxType6(const QJsonValue &value, QWidget *parent = 0);
    MessageBoxType6(const QJsonObject &post, QWidget *parent = 0);

private:
    void init(const QJsonValue &value);
    void initPost(const QJsonObject &post);

signals:

public slots:
    void ImageInitFinished();

};

#endif // MESSAGEBOXTYPE6_H
