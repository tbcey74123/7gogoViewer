#ifndef MESSAGEBOXTYPE1_H
#define MESSAGEBOXTYPE1_H

#include "messagebox.h"

class QWidget;
class QLabel;

class QJsonValue;
class QJsonObject;

class MessageBoxType1 : public MessageBox {

    Q_OBJECT

    QLabel *memberText;

public:
    MessageBoxType1(const QJsonValue &value, QWidget *parent = 0);
    MessageBoxType1(const QJsonObject &post, QWidget *parent = 0);



private:
    void init(const QJsonValue &value);
    void initPost(const QJsonObject &post);

signals:

};

#endif // MESSAGEBOXTYPE1_H
