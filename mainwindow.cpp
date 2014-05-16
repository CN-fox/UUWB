#include "mainwindow.h"
#include<QDialog>
#include<QMovie>
#include"./sdk/WeiboParameters.h"
#include"./sdk/net/NetWorkManager.h"
#include"./sdk/api/UserAPI.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_clicked()
{
    user = new WeiBo();
    connect(user,SIGNAL(login_success()),this,SLOT(login_success()));
    user->login(this);
}

void MainWindow::login_success()
{
    ui->login->deleteLater();
    showhead();
}

void MainWindow::showhead(){
    UserAPI api =UserAPI(user);
    api.show();

    QString str_url = "https://api.weibo.com/2/users/show.json";
    str_url.append("?access_token=").append(user->gettoken()).append("&uid=").append(user->getUid());
    manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(showBack(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl(str_url)));

    ui->head_img->setText(QString("head pic loading..."));
}

void MainWindow::showBack(QNetworkReply *reply)
{
    QByteArray json =  reply->readAll();
    //    qDebug(json.data());
    QJsonParseError error;
    QJsonDocument json_document = QJsonDocument::fromJson(json,&error);

    if (error.error == QJsonParseError::NoError) {
        QVariantMap map = json_document.toVariant().toMap();
        QString head_url = map["profile_image_url"].toString();
        manager->get(QNetworkRequest(QUrl(head_url)));
    }else {
        QDateTime now;
        QPixmap * currentPicture = new QPixmap();

        currentPicture->loadFromData(json);
        QString filename = now.currentDateTime().toString("yyMMddhhmmss.jpg");
        currentPicture->save(filename);

        QString currentFileName = filename;
        QMovie * move = new QMovie(currentFileName);
        ui->head_img->setMovie(move);
        qDebug("head show");
        move->start();
    }
}

