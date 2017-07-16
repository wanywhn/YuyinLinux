#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QTcpSocket>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
  PORT = 9913;
  //    blockSize=0;
  //    auto interfaceSelectBox=ui->interFaceSelect;
  //    QList<QNetworkInterface> localAllInterfaces =
  //    QNetworkInterface::allInterfaces();
  //
  //    for(auto interface:localAllInterfaces){
  //        if(interface.name().isEmpty()|interface.name()=="lo")
  //            continue;
  //        qDebug()<<"name:"<<interface.name();
  //        qDebug()<<"MAC:"<<interface.hardwareAddress();
  //        for(auto entry:interface.addressEntries()){
  //            if(entry.broadcast().toString().isEmpty())
  //                continue;
  //            qDebug()<<"IP:"<<entry.ip().toString();
  //            qDebug()<<"NETMASK:"<<entry.netmask().toString();
  //            qDebug()<<"BROADCAST:"<<entry.broadcast().toString();
  //            qDebug()<<"-----";
  //            interfaceSelectBox->addItem(interface.name()+","+entry.broadcast().toString());
  //        }
  //    }
  //
  //    auto num=interfaceSelectBox->count();
  //    for(int i=0;i!=num;i++){
  //        QString item=interfaceSelectBox->itemText(i);
  //        QString ip=item.split(",").at(1);
  //        if(ip.split(".").at(3)!="255"){
  //            emit wrongIP();
  //        }else{
  //            client=new QTcpSocket(this);
  //            connect(client,&QTcpSocket::readyRead,this,&Widget::ReadMessage);
  //            connect(client,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
  //            QHostAddress add;
  //            add.setAddress(ip);
  //
  //            client->connectToHost(add,PORT);
  //            qDebug()<<"connectchenggong:"<<add;
  //            //TODO 添加连接错误信息
  //            break;
  //        }
  //
  //
  //
  //    }

  reveive = new QUdpSocket(this);
  reveive->bind(PORT, QUdpSocket::ShareAddress);
  connect(reveive, &QUdpSocket::readyRead, this,
          &Widget::processPendingDatagram);
}

Widget::~Widget() { delete ui; }

void Widget::ReadMessage() {
  //    QDataStream in(client);
  //    in.setVersion(QDataStream::Qt_5_6);
  //
  //    if(blockSize==0){
  //        if(client->bytesAvailable()<(int)sizeof(quint16))
  //            return;
  //        in>>blockSize;
  //        qDebug()<<"长度:"<<blockSize;
  //    }
  //    if(client->bytesAvailable()<blockSize)
  //        return;
  //    in>>message;
  //    qDebug()<<"MESSAGE:"<<message;
  //    blockSize=0;
}

void Widget::displayError(QAbstractSocket::SocketError) {
  qDebug() << client->errorString();
}

void Widget::processPendingDatagram() {

    qDebug()<<"-------";
  qDebug() << "daolai";
//  blockSignals(true);
    QByteArray datagram;
  while (reveive->hasPendingDatagrams()) {
    datagram.resize(reveive->pendingDatagramSize());
    reveive->readDatagram(datagram.data(), datagram.size());
    QString tmp(datagram);
    qDebug() << tmp<<"-";
  }
    datagram.resize(reveive->pendingDatagramSize());
    reveive->readDatagram(datagram.data(), datagram.size());
    QString tmp(datagram);
//  blockSignals(false);
}
