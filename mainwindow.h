#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QDomDocument>
#include <QTreeWidget>
#include <QListWidget>
#include<controler.h>


namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void readXml(QNetworkReply *reply);
    //void itemActivated(QTreeWidgetItem * item);
    void itemClicked(QListWidgetItem * item);
    void itemDoubleClicked(QListWidgetItem *item);
    void requestXml(QUrl url);
    void parseXml();
private:
    QString currentTag;
    QString linkString;
    QString titleString;
    QString dateString;

    //QTreeWidgetItem *feed;
    QListWidgetItem *feed;

    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
    QXmlStreamReader xml;
    int retryDelaySec;

        FeedsController * feedscontroller;
        ItemsController *itemscontroller;
        ReadController *readcontroller;

};

#endif // MAINWINDOW_H
