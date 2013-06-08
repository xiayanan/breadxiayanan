#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"controler.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    retryDelaySec = 1;
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
                this, SLOT(readXml(QNetworkReply*)));
    connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(itemClicked(QListWidgetItem*)));
    connect(ui->listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(itemDoubleClicked(QListWidgetItem*)));
    QString addr = "http://sse.tongji.edu.cn/SSEMainRSS.aspx";
    QUrl url(addr);
    requestXml(url);

        FeedsToolBar *feedstool=new FeedsToolBar();
        feedscontroller=new FeedsController(feedstool,ui->listWidget);
        ItemsToolBar *itemstool=new ItemsToolBar();
        itemscontroller=new ItemsController(itemstool,ui->listWidget_2);

        ReadToolBar *readtool=new ReadToolBar();
        readcontroller=new ReadController(readtool,ui->webView);

//    QString addrMacx = "http://www.macx.cn/forum.php?mod=rss&fid=4000";
//    QUrl urlMacx(addrMacx);
//    requestXml(urlMacx);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::requestXml(QUrl url){
    xml.clear();

    manager->get(QNetworkRequest(url));
}

void MainWindow::readXml(QNetworkReply *reply){
    if (reply->error() != QNetworkReply::NoError) {
            setToolTip(tr("Failed to retrieve weather data:\n%1")
                       .arg(reply->errorString()));
            QTimer::singleShot(retryDelaySec,
                               this, SLOT(requestXml()));
            retryDelaySec <<= 1;
            if (retryDelaySec > 60 * 60)
                retryDelaySec = 1;
            return;
    } else {
        retryDelaySec = 1;
        QDomDocument document;
        xml.addData(reply->readAll());
        parseXml();
        QTimer::singleShot(60 * 60 * 1000, this, SLOT(requestXml()));

    }
}


void MainWindow::parseXml()
{

    while (!xml.atEnd()) {
        xml.readNext();
        if (xml.isStartElement()) {

            if (xml.name() == "item"){

                if (titleString!=""){
                   feed = new QListWidgetItem;
                   feed->setText(titleString);
                   feed->setText(linkString);
                   ui->listWidget->addItem(feed);

                }

                linkString.clear();
                titleString.clear();
                dateString.clear();
            }

            currentTag = xml.name().toString();
        } else if (xml.isEndElement()) {
             if (xml.name() == "item") {

                 QListWidgetItem *item = new QListWidgetItem();
                item->setText( titleString);
                item->setText( dateString);
                item->setText( linkString);
                ui->listWidget->addItem(item);

                titleString.clear();
                linkString.clear();
                dateString.clear();
            }

        } else if (xml.isCharacters() && !xml.isWhitespace()) {
            if (currentTag == "title")
                titleString += xml.text().toString();
            else if (currentTag == "link")
                linkString += xml.text().toString();
            else if (currentTag == "pubDate")
                dateString += xml.text().toString();
        }
    }
    if (xml.error() && xml.error() != QXmlStreamReader::PrematureEndOfDocumentError) {
        qWarning() << "XML ERROR:" << xml.lineNumber() << ": " << xml.errorString();
    }
}

void MainWindow::itemClicked(QListWidgetItem *item){
    QUrl url(item->text());
    ui->webView->load(url);
    ui->webView->show();
}

void MainWindow::itemDoubleClicked(QListWidgetItem *item){
    QUrl url(item->text());
    ui->webView->load(url);
    ui->webView->show();
}

