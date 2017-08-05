#include "register_dialog.h"
#include "ui_register_dialog.h"

Register_Dialog::Register_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register_Dialog)
{
    ui->setupUi(this);
    //this->setWindowFlag(Qt::WindowStaysOnTopHint,true);
    this->setWindowTitle(tr("用户注册"));
    this->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
}

Register_Dialog::~Register_Dialog()
{
    delete ui;
}

void Register_Dialog::on_exit_btn_clicked()
{
    this->close();
   // exit(EXIT_SUCCESS);
}
