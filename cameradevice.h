#ifndef CAMERADEVICE_H
#define CAMERADEVICE_H
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraInfo>
#include <QCameraImageCapture>
#include <QObject>
#include <QThread>
#include <QImage>
class CameraDevice : public QCameraViewfinder
{
    Q_OBJECT
public:
    CameraDevice();
signals:

public slots:
    void open_Camera();
    void close_Camera();
    void select_Device(QCameraInfo);
   // void accept_oriFrame(int,QImage);
    //test
    void imageCaptureslot();
private:
    QCamera *m_Camera;
public:
    QImage ori_frame;
    QCameraImageCapture *m_frame;
public:
    QCameraInfo DeviceInfo;

};

#endif // CAMERADEVICE_H
