#include"AccessTokenKeeper.h"
#include<QFile>

AccessTokenKeeper::AccessTokenKeeper()
{

}

void AccessTokenKeeper::keep(WeiBo* wiebo)
{
    QFile data("save");
    if (data.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream out(&data);
        out << "test";
    }
}

void AccessTokenKeeper::clear()
{

}

void AccessTokenKeeper::read(WeiBo* weibo)
{

}
