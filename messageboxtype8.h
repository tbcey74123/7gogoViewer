#ifndef MESSAGEBOXTYPE8_H
#define MESSAGEBOXTYPE8_H

#include "messagebox.h"

class QWidget;
class QLabel;

class Image;

class QJsonValue;
class QJsonObject;

class MessageBoxType8 : public MessageBox {

    Q_OBJECT

    Image *img;
    QLabel *video, *memberText;

public:
    MessageBoxType8(const QJsonValue &value, QWidget *parent = 0);
    MessageBoxType8(const QJsonObject &post, QWidget *parent = 0);

private:
    void init(const QJsonValue &value);
    void initPost(const QJsonObject &post);

signals:

public slots:
    void ImageInitFinished();

};

#endif // MESSAGEBOXTYPE8_H
