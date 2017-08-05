#include "serport_dialog.h"
#include "ui_serport_dialog.h"
#include  <QDebug>
serport_Dialog::serport_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::serport_Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("通信串口设置"));
    this->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
}

serport_Dialog::~serport_Dialog()
{
    delete ui;
}

void serport_Dialog::on_return_btn_clicked()
{
   returnSignal(1);
}

void serport_Dialog::on_openSerport_btn_clicked()
{
    //测试用函数
      qDebug()<<"串口号"<<ui->port_combox->currentText()<<endl;
      qDebug()<<"波特率"<<ui->baund_combox->currentText()<<endl;
}
