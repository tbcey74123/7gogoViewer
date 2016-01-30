#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QWidget>
#include <QFont>
#include <QLabel>
#include <QGridLayout>

class ContentBox;


class QTextBrowser;

class QJsonValue;
class QJsonObject;

class QNetworkReply;

class MessageBox : public QWidget {
    Q_OBJECT

protected:
    int messageNum;

    QJsonValue *value;

    ContentBox *parent;

    QLabel *memberName;

    QGridLayout *layout;



public:
    explicit MessageBox(QWidget *parent);
    explicit MessageBox(const QJsonValue &value, QWidget *parent = 0);
    explicit MessageBox(const QJsonObject &post, QWidget *parent = 0);
    explicit MessageBox(const QJsonValue &value, const int &messageNum, QWidget *parent = 0);
    explicit MessageBox(const QJsonObject &post, const int &messageNum, QWidget *parent = 0);

    void setMessageNum(const int messageNum);
    int getMessageNum();

    static int determineType(const QJsonObject &post);
    static MessageBox *fromJson(const QJsonValue &value, QWidget *parent = 0);
    static MessageBox *fromJson(const QJsonObject &post, QWidget *parent = 0);

private:
    void init(const QJsonValue &value);
    void initPost(const QJsonObject &post);
    void initMemberName(const QString &name);

signals:
    //void boxFinished();
    void boxFinished(MessageBox *box);

public slots:


};

#endif // MESSAGEBOX_H
