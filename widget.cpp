#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    socket = new QTcpSocket;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString ip = ui->lineEdit->text();
    QString port = ui->lineEdit_2->text();
    socket->connectToHost(QHostAddress(ip),port.toShort());
    connect(socket,&QTcpSocket::connected,[this]()
    {
        QMessageBox::information(this,"Message","OK");
    });

    connect(socket,&QTcpSocket::disconnected,[this]()
            {
        QMessageBox::warning(this,"Message","Error");
    });
}


void Widget::on_pushButton_2_clicked()
{
    QByteArray s1 = ui->lineEdit_3->text().toUtf8();

    socket->write(s1);
}

