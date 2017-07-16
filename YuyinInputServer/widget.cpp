#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QTcpSocket>
#include <QPlainTextEdit>
Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
  PORT = 9913;
  /*
  QList<QNetworkInterface> localAllInterfaces =
      QNetworkInterface::allInterfaces();

  QString ip;
  QHostAddress add;
  for (QNetworkInterface interface : localAllInterfaces) {
    qDebug() << "name:" << interface.name();
    if (interface.name().isEmpty()|interface.name()=="lo")
      continue;
    qDebug() << "MAC:" << interface.hardwareAddress();
    for (auto entry : interface.addressEntries()) {
      if (entry.broadcast().toString().isEmpty())
        continue;
      qDebug() << "IP:" << entry.ip().toString();
      qDebug() << "NETMASK:" << entry.netmask().toString();
      qDebug() << "BROADCAST:" << entry.broadcast().toString();
      qDebug() << "-----";
      ip= entry.ip().toString();
      entry.ip().
      add.setAddress(entry.ip());
    }
  }
  */
//  tcpServer=new QTcpServer(this);
//  QHostAddress add;
//  add.setAddress(QString("0.0.0.0"));
//;
//  tcpServer=new QTcpServer(this);
//  if(!tcpServer->listen(QHostAddress::AnyIPv4,PORT)){
//      qDebug()<<"jianlishibai";
//  }
//  qDebug()<<"chenggong42";
//  connect(tcpServer,&QTcpServer::newConnection,this,&Widget::sendMessage);
//  qDebug()<<"chengong44";
//

   connect(ui->textEdit,&QPlainTextEdit::textChanged,this,&Widget::textChanged);

}

Widget::~Widget() { delete ui; }

QByteArray Widget::makeMessage(QString str)
{
    QByteArray block;
    qDebug()<<"make new message";
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_6);
    out<<(quint16)0;
    out<<str;
    out.device()->seek(0);
    out<<(quint16)(block.size()-sizeof(quint16));

    return block;
}

void Widget::sendMessage()
{
    //QString str="lian jie cheng gong ";
    //QByteArray block = makeMessage(str);

    //clientConnection=tcpServer->nextPendingConnection();
    //connect(clientConnection,&QTcpSocket::disconnected,
    //        clientConnection,&QTcpSocket::deleteLater);
    //clientConnection->write(block);
    //qDebug()<<"fasongchenggong";
}

void Widget::textChanged()
{
   // if(clientConnection==nullptr){
   //     qDebug()<<"ERROR wei lian jie ";
   //     return;
   // }
   // QByteArray block=makeMessage(ui->textEdit->document()->toPlainText());
   // blockSignals(true);
   // ui->textEdit->document()->clear();
   // blockSignals(false);
   // clientConnection->write(block);
//    blockSignals(true);
    qDebug()<<"jinru";
QByteArray datagram;
    datagram=ui->textEdit->document()->toPlainText().toLocal8Bit();
    sender=new QUdpSocket(this);
    sender->writeDatagram(datagram.data(),datagram.size(),
                          QHostAddress::Broadcast,PORT);
//    blockSignals(false);
}

void Widget::on_pushButton_clicked()
{
   ui->textEdit->clear();
}
