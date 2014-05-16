#ifndef WEIBO_H
#define WEIBO_H

#include <QMainWindow>
#include"./net/NetWorkManager.h"
#include"WeiBoAction.h"
#include<QtWebKitWidgets/QWebView>
#include "globaldata.h"

class WeiBo : public QObject
{
    Q_OBJECT
public:
    explicit WeiBo(QObject *parent = 0);
    void setuid(QString);
    void settoken(QString);
    void set_expires_in(int);
    void set_remind_in(int);
    QString getUid();
    QString gettoken();
    void login(QMainWindow *);

protected:
    QString uid;
    QString access_token;
    int remind_in;
    int expires_in;

private:
    NetWorkManager * manager;
    QWebView *view;
signals:
    void login_success();

public slots:
    void handleAddressChanged(const QUrl&);
    void  netBack(QNetworkReply*);

};

#endif // WEIBO_H
