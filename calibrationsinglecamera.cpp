#include "calibrationsinglecamera.h"
#include "ui_calibrationsinglecamera.h"

CalibrationSingleCamera::CalibrationSingleCamera(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalibrationSingleCamera)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("单目相机标定"));
    this->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
}

CalibrationSingleCamera::~CalibrationSingleCamera()
{
    delete ui;
}

void CalibrationSingleCamera::on_returnBtn_clicked()
{
    returnSignal(1);
}
