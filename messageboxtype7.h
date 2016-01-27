#ifndef MESSAGEBOXTYPE7_H
#define MESSAGEBOXTYPE7_H

#include "messagebox.h"

class QWidget;
class QLabel;

class Image;

class QJsonValue;
class QJsonObject;

class QNetworkAccessManager;
class QNetworkReply;

class MessageBoxType7 : public MessageBox {

    Q_OBJECT

    ContentBox *contentBox;

    QLabel *memberText;
    Image *img;

    QNetworkAccessManager *nam;
    QMetaObject::Connection conn;

public:
    MessageBoxType7(const QJsonValue &value, QWidget *parent = 0);
    MessageBoxType7(const QJsonObject &post, QWidget *parent = 0);

private:
    void init(const QJsonValue &value);
    void initPost(const QJsonObject &post);


public slots:
    void ImageDownloadFinished(QNetworkReply *reply);


};

#endif // MESSAGEBOXTYPE7_H
