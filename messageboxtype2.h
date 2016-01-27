#ifndef MESSAGEBOXTYPE2_H
#define MESSAGEBOXTYPE2_H

#include "messagebox.h"

class QWidget;
class QLabel;

class Image;

class QJsonValue;
class QJsonObject;

class QNetworkAccessManager;
class QNetworkReply;

class MessageBoxType2 : public MessageBox {

    Q_OBJECT

    ContentBox *contentBox;

    Image *img;

public:
    MessageBoxType2(const QJsonValue &value, QWidget *parent = 0);
    MessageBoxType2(const QJsonObject &post, QWidget *parent = 0);

private:
    void init(const QJsonValue &value);
    void initPost(const QJsonObject &post);

public slots:
    void ImageInitFinished();


};

#endif // MESSAGEBOXTYPE2_H
