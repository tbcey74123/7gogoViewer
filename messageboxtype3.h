#ifndef MESSAGEBOXTYPE3_H
#define MESSAGEBOXTYPE3_H

#include "messagebox.h"

class QWidget;
class QLabel;

class Image;

class QJsonValue;
class QJsonObject;
class QNetworkAccessManager;
class QNetworkReply;

class MessageBoxType3 : public MessageBox {

    Q_OBJECT

    ContentBox *contentBox;

    Image *img;

public:
    MessageBoxType3(const QJsonValue &value, QWidget *parent = 0);
    MessageBoxType3(const QJsonObject &post, QWidget *parent = 0);

private:
    void init(const QJsonValue &value);
    void initPost(const QJsonObject &post);

public slots:
    void ImageInitFinished();


};

#endif // MESSAGEBOXTYPE3_H
