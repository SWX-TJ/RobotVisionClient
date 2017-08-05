#ifndef GOALDETECTION_DIALOG_H
#define GOALDETECTION_DIALOG_H

#include <QDialog>

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

private slots:
       void on_returnBtn_clicked();

private:
    Ui::GoalDetection_Dialog *ui;
};

#endif // GOALDETECTION_DIALOG_H
