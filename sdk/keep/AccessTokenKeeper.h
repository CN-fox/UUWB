#ifndef ACCESSTOKENKEEPER_H
#define ACCESSTOKENKEEPER_H

#include"../WeiBo.h"

class AccessTokenKeeper{
public:
    static void keep(WeiBo*);
    static void clear();
    static void read(WeiBo*);
private:
        AccessTokenKeeper();
};

#endif // ACCESSTOKENKEEPER_H
