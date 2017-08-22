#ifndef GOALDETECTION_DIALOG_H
#define GOALDETECTION_DIALOG_H
#include <QDialog>
#include <QWidget>
#include "roadrobotmodesetwidget.h"
#include "basketballrobotmodesetwidget.h"
#define Mode_RoadRobot     1
#define Mode_BastBallRobot 2
#define Mode_SoccerRobot   3
namespace Ui {
class GoalDetection_Dialog;
}
class GoalDetection_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit GoalDetection_Dialog(QWidget *parent = 0);
    ~GoalDetection_Dialog();
signals:
       void returnSignal(int);
       void send_RobotMode(int);
private slots:
       void on_returnBtn_clicked();
       void on_comboBox_currentIndexChanged(int index);
       void on_SetBtn_clicked();

public:
       RoadRobotModeSetWidget *m_roadRobot;
       BasketBallRobotModeSetWidget *m_basketBallRobot;
       QWidget* returnCurrentWidget(QString currentWidgetName);
public:
       QString currentWidget;
       int RobotMode;

private:
    Ui::GoalDetection_Dialog *ui;
};

#endif // GOALDETECTION_DIALOG_H
