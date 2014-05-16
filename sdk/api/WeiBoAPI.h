#ifndef WEIBOAPI_H
#define WEIBOAPI_H
#include "../WeiBo.h"
#include "../net/NetWorkManager.h"
#include <QObject>

class WeiBoAPI
{
public:
    WeiBoAPI(WeiBo*);

protected:
    WeiBo *weibo;
    NetWorkManager* getNetWorkManager();

private:
    NetWorkManager *manager;
};

#endif // WEIBOAPI_H
