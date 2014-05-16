#include"WeiBoAction.h"
#include"globaldata.h"

QUrl WeiBoAction::getUrl(Action action){
    QString str_url;
    switch (action) {
    case SHOW:
        str_url = QString(API_HOST).append( "2/users/show.json");
        break;
    case LOGIN:
        str_url = QString(OAUTH2_HOST).append("authorize?client_id=").append(CLIENT_ID).append("&response_type=code&redirect_uri=").append(REDIRECT_URI);
    default:
        break;
    }
    return QUrl(str_url);
}
