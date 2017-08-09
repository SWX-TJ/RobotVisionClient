#include "roadrobotmodesetwidget.h"
#include "ui_roadrobotmodesetwidget.h"

RoadRobotModeSetWidget::RoadRobotModeSetWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RoadRobotModeSetWidget)
{
    ui->setupUi(this);
}

RoadRobotModeSetWidget::~RoadRobotModeSetWidget()
{
    delete ui;
}
