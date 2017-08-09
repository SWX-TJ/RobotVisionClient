#ifndef ROADROBOTMODESETWIDGET_H
#define ROADROBOTMODESETWIDGET_H

#include <QWidget>

namespace Ui {
class RoadRobotModeSetWidget;
}

class RoadRobotModeSetWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RoadRobotModeSetWidget(QWidget *parent = 0);
    ~RoadRobotModeSetWidget();

private:
    Ui::RoadRobotModeSetWidget *ui;
};

#endif // ROADROBOTMODESETWIDGET_H
