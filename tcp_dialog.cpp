#include "tcp_dialog.h"
#include "ui_tcp_dialog.h"
#include <QDebug>
Tcp_Dialog::Tcp_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tcp_Dialog)
{
    ui->setupUi(this);
   // this->setWindowFlag(Qt::WindowStaysOnTopHint,true);
    this->setWindowTitle(tr("服务器连接设置"));
    this->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
}

Tcp_Dialog::~Tcp_Dialog()
{
    delete ui;
}

void Tcp_Dialog::on_Connect_btn_clicked()
{
  //测试用函数
    qDebug()<<"Ip地址"<<ui->IPAddress_linedit->text()<<endl;
    qDebug()<<"端口"<<ui->Port_linedit->text()<<endl;
}

void Tcp_Dialog::on_Return_btn_clicked()
{
    returnSignal(2);
}
