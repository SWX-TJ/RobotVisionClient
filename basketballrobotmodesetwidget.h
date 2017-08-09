#ifndef BASKETBALLROBOTMODESETWIDGET_H
#define BASKETBALLROBOTMODESETWIDGET_H

#include <QWidget>

namespace Ui {
class BasketBallRobotModeSetWidget;
}

class BasketBallRobotModeSetWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BasketBallRobotModeSetWidget(QWidget *parent = 0);
    ~BasketBallRobotModeSetWidget();

private:
    Ui::BasketBallRobotModeSetWidget *ui;
};

#endif // BASKETBALLROBOTMODESETWIDGET_H
