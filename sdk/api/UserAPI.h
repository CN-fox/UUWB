#ifndef USERAPI_H
#define USERAPI_H
#include "WeiBoAPI.h"
#include"../WeiBo.h"

class UserAPI : public WeiBoAPI
{
public:
    UserAPI(WeiBo*);
    void show();
};

#endif // USERAPI_H
