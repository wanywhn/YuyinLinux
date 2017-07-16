#ifndef WIDGET_H
#define WIDGET_H

#include <QTcpServer>
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

    QByteArray makeMessage(QString str);

private slots:
    void sendMessage();
    void textChanged();
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QTcpServer *tcpServer;
    quint16 PORT;
    QTcpSocket *clientConnection;


    QUdpSocket *sender;

};

#endif // WIDGET_H
