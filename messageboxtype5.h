#ifndef MESSAGEBOXTYPE5_H
#define MESSAGEBOXTYPE5_H

#include "messagebox.h"

class QWidget;

class QJsonValue;

class MessageBoxType5 : public MessageBox {

    Q_OBJECT

    QLabel *retalkFrom;
    MessageBox *retalkContent;

public:
    MessageBoxType5(const QJsonValue &value, QWidget *parent = 0);
    MessageBoxType5(const QJsonObject &post, QWidget *parent = 0);


private:
    void init(const QJsonValue &value);
    void initPost(const QJsonObject &post);
    void initRetalkFrom(QString src);

signals:

};

#endif // MESSAGEBOXTYPE5_H
