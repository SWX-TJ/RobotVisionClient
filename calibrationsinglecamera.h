#ifndef CALIBRATIONSINGLECAMERA_H
#define CALIBRATIONSINGLECAMERA_H

#include <QDialog>

namespace Ui {
class CalibrationSingleCamera;
}

class CalibrationSingleCamera : public QDialog
{
    Q_OBJECT

public:
    explicit CalibrationSingleCamera(QWidget *parent = 0);
    ~CalibrationSingleCamera();
signals:
    void returnSignal(int);
private slots:
    void on_returnBtn_clicked();
private:
    Ui::CalibrationSingleCamera *ui;
};

#endif // CALIBRATIONSINGLECAMERA_H
