#ifndef WEIBOPARAMETERS_H
#define WEIBOPARAMETERS_H

#include<map>
#include<QString>
#include<QMap>

using namespace std;

class WeiboParameters{

public:
    WeiboParameters();
    ~WeiboParameters();
    void setNeedToken(bool);
    bool isNeedToken();
    void setParam(QString,QString);
    QString get();


private:
    bool needtoken;
    QMap<QString,QString> m;
    map<QString,QString> params;
};



#endif // WEIBOPARAMETERS_H
