#include"WeiBoAPI.h"

WeiBoAPI::WeiBoAPI(WeiBo* weibo)
{

    this->weibo = weibo;
}


NetWorkManager* WeiBoAPI::getNetWorkManager()
{
    manager = new NetWorkManager();
    return manager;
}
