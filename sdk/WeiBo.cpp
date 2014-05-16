#include "WeiBo.h"
#include"./keep/AccessTokenKeeper.h"
WeiBo::WeiBo(QObject *parent) :
    QObject(parent)
{
}

QString  WeiBo::gettoken()
{
       return access_token;
}

QString WeiBo::getUid()
{
    return uid;
}

void WeiBo::settoken(QString token)
{
    this->access_token = token;
}

void WeiBo::setuid(QString uid)
{
    this->uid = uid;
}

void WeiBo::set_expires_in(int expires_in)
{
    this->expires_in = expires_in;
}

void WeiBo::set_remind_in(int remind_in)
{
    this->remind_in = remind_in;
}

void WeiBo::login(QMainWindow *window)
{
    QUrl url = WeiBoAction::getUrl(WeiBoAction::LOGIN);
    view = new QWebView(window);
    QObject::connect(view,SIGNAL(urlChanged(QUrl)),this,SLOT(handleAddressChanged(QUrl)));
    view->resize(700,500);
    view->load(url);
    view->show();
}

void WeiBo::handleAddressChanged(const QUrl &url)
{
    QString str_url = url.toString();
    if (str_url.startsWith("https://api.weibo.com/oauth2/default.html?error")) {
        //error
        qDebug(str_url.toLatin1().data());
    }else if (str_url.startsWith(REDIRECT_URI)) {
        //right
        int index_code = str_url.indexOf("=");
        QString code = str_url.right(str_url.length() - index_code - 1);
        qDebug(code.toLatin1().data());
        if (code.isNull()) {
            //error
        }else{
            QString access_token_url = QString(OAUTH2_HOST).append("access_token?client_id=2414195685&client_secret=b0164f6524159eac4ba40df7af3453f4&grant_type=authorization_code&redirect_uri=https://api.weibo.com/oauth2/default.html&code=").append(code);
            qDebug() << "token"+access_token_url;
            QNetworkAccessManager *manager1 = new QNetworkAccessManager(this);
            connect(manager1,SIGNAL(finished(QNetworkReply*)),this,SLOT(netBack(QNetworkReply*)));
            manager1->post(QNetworkRequest(QUrl(access_token_url)),"");
            qDebug("start get access_token");
        }

    }else{
        //others
        qDebug(str_url.toLatin1().data());
    }
}

void WeiBo::netBack(QNetworkReply *reply)
{
    qDebug("access_token get");
    QByteArray json =  reply->readAll();
    // qDebug(json.data());
    QJsonParseError error;
    QJsonDocument json_document = QJsonDocument::fromJson(json,&error);

    if(error.error == QJsonParseError::NoError){

        QVariantMap map = json_document.toVariant().toMap();
        settoken(map["access_token"].toString());
        setuid(map["uid"].toString());
        set_expires_in(map["expires_in"].toString().toInt(false,0));
        set_remind_in(map["remind_in"].toString().toInt(false,0));
        view->deleteLater();

        AccessTokenKeeper::keep(this);

        emit login_success();
    }else{

    }
}
