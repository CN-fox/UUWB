#include"NetWorkManager.h"
#include<QMessageBox>

//NetWorkManager::NetWorkManager()
//{
//    init();
//}

NetWorkManager::NetWorkManager(QObject *parent):
    QObject(parent)
{

}


void NetWorkManager::init()
{

}




void NetWorkManager::finish_slot(QNetworkReply* reply)
{
    QByteArray json =  reply->readAll();
    QJsonParseError error;
    QJsonDocument json_document = QJsonDocument::fromJson(json,&error);
    if (error.error == QJsonParseError::NoError) {
        QVariantMap map = json_document.toVariant().toMap();
        if (map.contains("error_code")) {
            //error
            emit on_error(json_document);
        }else{
            emit on_complete(json_document);
        }
    }
}

void NetWorkManager::handleAddressChanged(const QUrl& url)
{
    qDebug() << "handle" << url.path();
}

void NetWorkManager::post(QUrl url, WeiboParameters params)
{
    QString url_host = url.path();
    qDebug() << url_host;
    qDebug() << params.get();
}

void NetWorkManager::get(QUrl url, WeiboParameters params)
{
    QString url_host = url.path();
    url = QUrl(url_host.append(params.get()));
    qDebug() << url.path();
    manager = new QNetworkAccessManager();
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(finish_slot(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl(url)));
}
