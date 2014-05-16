#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include<QtNetwork>
#include<QtWebKitWidgets/QWebView>
#include"./sdk/WeiBo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void cc();

private slots:
    void on_login_clicked();
    void showBack(QNetworkReply *);
    void login_success();

private:
    Ui::MainWindow *ui;
    QWebView * view;
    WeiBo *user;
    QNetworkAccessManager * manager;
    void showhead();
};

#endif // MAINWINDOW_H
