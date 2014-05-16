#include"WeiboParameters.h"
#include "mainwindow.h"

WeiboParameters::WeiboParameters(){
}

WeiboParameters::~WeiboParameters()
{

}
void WeiboParameters::setNeedToken(bool needtoken)
{
    this->needtoken = needtoken;
}

void WeiboParameters::setParam(QString key, QString value)
{
    params.insert(pair<QString,QString>(key,value));
}

QString WeiboParameters::get()
{
    map <QString,QString>::iterator m1_Iter;
    QString param;
    for (m1_Iter = params.begin(); m1_Iter!=params.end(); ++m1_Iter) {
        param.append(m1_Iter->first).append("=").append(m1_Iter -> second).append("&");
    }
    return param;
}
