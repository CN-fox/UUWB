#include"AccessTokenKeeper.h"
#include<QJsonDocument>
#include<QFile>

AccessTokenKeeper::AccessTokenKeeper()
{

}

void AccessTokenKeeper::keep(WeiBo* weibo)
{
    QVariantMap map;
    map.insert("uid",weibo->getUid());
    map.insert("token",weibo->gettoken());
    map.insert("expires_in",weibo->getExpiresIn());
    QJsonObject json = QJsonObject::fromVariantMap(map);
    QJsonDocument document = QJsonDocument(json);
    QFile data("save");
    if (data.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream out(&data);
        out << document.toJson();
    }
}

void AccessTokenKeeper::clear()
{
    QFile data("save");
    if (data.exists()) {
        data.open(QFile::WriteOnly | QFile::Truncate);
        QTextStream out(&data);
        out << "";
    }
}

void AccessTokenKeeper::read(WeiBo* weibo)
{

}
