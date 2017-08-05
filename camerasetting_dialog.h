#ifndef CAMERASETTING_DIALOG_H
#define CAMERASETTING_DIALOG_H
#include <QDialog>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraInfo>
#include <QList>
#include "calibrationsinglecamera.h"
#define LEFT_CAMERA  1
#define RIGHT_CAMERA 2
#define ALL_CAMERA   3
#define SIGNALCAMERACALIBRATEWINDOW_NUM  1
namespace Ui {
class CameraSetting_Dialog;
}

class CameraSetting_Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit CameraSetting_Dialog(QWidget *parent = 0);
    ~CameraSetting_Dialog();
signals:
    void returnSignal(int);
    void send_UseCameraNum(int);
    void send_leftdeviceIndex(int);
    void send_rightdeviceIndex(int);
public:
    QList<QCameraInfo> m_camerainfo;
    QString temp_deviceName;
    int device_num;//设备列表
    int CameraUseNumFlag;//使用单目还是双目标志
    int leftCameraIndex;//左摄像头设备索引
    int rightCameraIndex;//右摄像头设备索引
    bool leftCameraEnable;//使能点击状态
    bool rightCameraEnable;
    CalibrationSingleCamera *m_calisingleCamera;
private slots:
    void on_SettingBtn_clicked();
    void on_ReturnBtn_clicked();
    void on_leftEnable_btn_clicked();
    void on_rightEnable_btn_clicked();
    void on_CalibrationSingleCamera_clicked();
    void shutdownSlaveWindow(int);
private:
    Ui::CameraSetting_Dialog *ui;
};

#endif // CAMERASETTING_DIALOG_H
