#include "goaldetection_dialog.h"
#include "ui_goaldetection_dialog.h"

GoalDetection_Dialog::GoalDetection_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GoalDetection_Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("目标识别设定"));
    this->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
}

GoalDetection_Dialog::~GoalDetection_Dialog()
{
    delete ui;
}

void GoalDetection_Dialog::on_returnBtn_clicked()
{
    returnSignal(4);
}
