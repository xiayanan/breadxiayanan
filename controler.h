#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QMainWindow>
#include <QtNetwork>
#include <QListWidget>
#include <QPushButton>
#include <QWebView>
#include <QDomDocument>
#include "ui_mainwindow.h"


class FeedsToolBar :public QObject{
    Q_OBJECT
public:
    //explicit FeedsToolBar(QObject *parent = 0);
    FeedsToolBar();
   // FeedsToolBar(FeedsToolBar* feedstoolbar);
    ~FeedsToolBar();
public slots:
    void addsse();
    void refresh();
private:

    Ui::MainWindow *ui;
    QPushButton* addsse_button;
    QPushButton* refresh_button;
};

class ItemsToolBar :public QObject{
    Q_OBJECT
public:
    ItemsToolBar();
    //ItemsToolBar(ItemsToolBar* itemstoolbar);
    ~ItemsToolBar();
public slots:
    void favoritelist();
    void hasreadlist();
    void alllist();
private:
     Ui::MainWindow *ui;
    QPushButton* favorite_button;
    QPushButton* hasread_button;
    QPushButton* all_button;
};
class ReadToolBar :public QObject{
    Q_OBJECT
public:
    ReadToolBar();
    //ReadToolBar(ReadToolBar* readtoolbar);
    ~ReadToolBar();
public slots:
    void addfavor();
private:
     Ui::MainWindow *ui;
    QPushButton* addfavorbutton;
};

class FeedsController{
public:
    FeedsController(FeedsToolBar* feedstools,QListWidget* list);
    ~FeedsController();
private:
    FeedsToolBar* feedstools;
    QListWidget* feedsList;
};

class ItemsController{
public:
    ItemsController(ItemsToolBar* itemstools,QListWidget* list);
    ~ItemsController();
private:
    ItemsToolBar* itemstools;
    QListWidget* itemsList;
};

class ReadController{
public:
    ReadController(ReadToolBar* readtools,QWebView* view);
    ~ReadController();
private:
    ReadToolBar* readtools;
    QWebView* readview;
};


#endif // CONTROLLER_H
