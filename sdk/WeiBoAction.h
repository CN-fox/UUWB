#ifndef WEIBOACTION_H
#define WEIBOACTION_H

#include<QUrl>

class WeiBoAction{

public:
    enum Action{
        SHOW,
        LOGIN
    };
    static QUrl getUrl(Action);
};


#endif // WEIBOACTION_H
