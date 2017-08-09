#include "basketballrobotmodesetwidget.h"
#include "ui_basketballrobotmodesetwidget.h"

BasketBallRobotModeSetWidget::BasketBallRobotModeSetWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BasketBallRobotModeSetWidget)
{
    ui->setupUi(this);
}

BasketBallRobotModeSetWidget::~BasketBallRobotModeSetWidget()
{
    delete ui;
}
