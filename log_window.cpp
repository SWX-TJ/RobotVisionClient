#include "log_window.h"
#include "ui_log_window.h"

Log_window::Log_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Log_window)
{
    ui->setupUi(this);
    //this->setWindowFlag(Qt::WindowStaysOnTopHint,true);
    this->setWindowTitle(tr("双足机器人客户端"));
    this->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
  m_client = new Client_mainwindow;
  m_register = new Register_Dialog;
}

Log_window::~Log_window()
{
    delete ui;
}

void Log_window::on_log_btn_clicked()
{

    m_client->show();
    this->close();
}

void Log_window::on_exit_btn_clicked()
{
    exit(EXIT_SUCCESS);
}

void Log_window::on_register_btn_clicked()
{

  m_register->show();
}
