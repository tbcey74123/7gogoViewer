#ifndef MESSAGEBOXTYPE4_H
#define MESSAGEBOXTYPE4_H

#include "messagebox.h"

class QWidget;
class QLabel;

class QJsonValue;
class QJsonObject;

class MessageBoxType4 : public MessageBox {

    Q_OBJECT

    enum {commentOffset = 20};

    QLabel *memberText, *userName, *commentText;

public:
    MessageBoxType4(const QJsonValue &value, QWidget *parent = 0);
    MessageBoxType4(const QJsonObject &post, QWidget *parent = 0);


private:
    void init(const QJsonValue &value);
    void initPost(const QJsonObject &post);

signals:

};

#endif // MESSAGEBOXTYPE4_H
