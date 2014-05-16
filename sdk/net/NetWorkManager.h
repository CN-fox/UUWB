#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include<QtNetwork>
#include"../WeiboParameters.h"

class NetWorkManager : public QObject
{
    Q_OBJECT
public:
    explicit NetWorkManager(QObject *parent = 0);
    void get(QUrl,WeiboParameters);
    void post(QUrl,WeiboParameters);

signals:
    void finish();
    void on_error(QJsonDocument);
    void on_complete(QJsonDocument);
public slots:
    void finish_slot(QNetworkReply*);
    void handleAddressChanged(const QUrl&);

private:
    QNetworkAccessManager * manager;
    void init();

};



#endif // NETWORKMANAGER_H
