#include "cameradevice.h"
#include <QDebug>
CameraDevice::CameraDevice()
{
}

void CameraDevice::open_Camera()
{
   m_Camera = new QCamera(DeviceInfo);
   m_Camera->setViewfinder(this);
   m_frame   = new QCameraImageCapture(m_Camera);
   m_Camera->setCaptureMode(QCamera::CaptureStillImage);
   m_Camera->start();
   connect(m_frame,SIGNAL(imageCaptured(int,QImage)),this,SLOT(accept_oriFrame(int,QImage)));
}

void CameraDevice::close_Camera()
{
    m_Camera->stop();
}

void CameraDevice::select_Device(QCameraInfo CameraInfo)
{
    DeviceInfo  = CameraInfo;
}


void CameraDevice::imageCaptureslot()
{
    m_frame->capture("ss");
}
