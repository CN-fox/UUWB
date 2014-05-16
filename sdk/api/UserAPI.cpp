#include "UserAPI.h"

UserAPI::UserAPI(WeiBo* weibo):
    WeiBoAPI(weibo)
{

}

void UserAPI::show(){
    QUrl  url = WeiBoAction::getUrl(WeiBoAction::SHOW);
    WeiboParameters *params = new WeiboParameters();
    params->setNeedToken(false);
    params->setParam("access_token",weibo->gettoken());
    params->setParam("uid",weibo->getUid());
    getNetWorkManager()->get(url,*params);
}
