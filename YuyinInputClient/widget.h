#ifndef WIDGET_H
#define WIDGET_H

#include <QTcpSocket>
#include <QUdpSocket>
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

signals:
    void wrongIP();
private slots:
    void ReadMessage();
    void displayError(QAbstractSocket::SocketError);


    void processPendingDatagram();
private:
    Ui::Widget *ui;
    QTcpSocket *client;
    quint16 PORT;
    qint16 blockSize;
    QString message;


    QUdpSocket *reveive;
};

#endif // WIDGET_H
