#include "Controler.h"
#include <iostream>
#include <QApplication>
using namespace std;

FeedsController::FeedsController(FeedsToolBar* feedstools,QListWidget* list)
{
    this->feedstools=feedstools;
    this->feedsList=list;
}

ItemsController::ItemsController(ItemsToolBar* itemstools,QListWidget* list)
{
    this->itemstools=itemstools;
    this->itemsList=list;
}

ReadController::ReadController(ReadToolBar* readtools,QWebView* view)
{
    this->readtools=readtools;
    this->readview=view;
}

FeedsToolBar::FeedsToolBar()
{
    //addsse_button=ui->addButton;
    //refresh_button=ui->refreshButton;
    //connect(ui->addButton,SIGNAL(clicked()),this,SLOT(addsse()));
   // connect(refresh_button,SIGNAL(clicked()),this,SLOT(refresh()));
}

FeedsToolBar::~FeedsToolBar()
{
    delete ui;
}

void FeedsToolBar::addsse(){
    //点击添加按钮时的响应,应该是出一个对话框,填要加的sse

}
void FeedsToolBar::refresh(){
    //点击刷新按钮时的响应
}

ItemsToolBar::ItemsToolBar()
{
    //favorite_button=ui->favoriteButton;
    //hasread_button=ui->unreadButton;
    //all_button=ui->allButton;
    //connect(favorite_button,SIGNAL(clicked()),this,SLOT(favoritelist()));
   // connect(hasread_button,SIGNAL(clicked()),this,SLOT(hasreadlist()));
   // connect(all_button,SIGNAL(clicked()),this,SLOT(alllist()));
}

ItemsToolBar::~ItemsToolBar(){

}

void ItemsToolBar::favoritelist(){
    //点击喜欢按钮时列出标记喜欢的items
}

void ItemsToolBar::hasreadlist(){
    //点击已读按钮时列出已读的items
}

void ItemsToolBar::alllist(){
    //点击所有按钮时列出的所有items
}

ReadToolBar::ReadToolBar()
{
   // addfavorbutton=ui->addFavorButton;
//    connect(addfavorbutton,SIGNAL(clicked()),this,SLOT(addfavor()));
}

ReadToolBar::~ReadToolBar(){

}

void ReadToolBar::addfavor(){
    //点击喜欢按钮时标记喜欢
}
