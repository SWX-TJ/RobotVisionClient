#ifndef IMAGE_PROCESSTHREAD_H
#define IMAGE_PROCESSTHREAD_H
#include <QObject>
#include <QThread>
#include <QImage>
#include <opencv.hpp>
#define LEFT_CAMERA  1
#define RIGHT_CAMERA 2
#define ALL_CAMERA   3
using namespace cv;
class Image_processThread : public QThread
{
    Q_OBJECT
public:
   Image_processThread();
   //test
public:
   int leftCameraIndex;//左相机设备索引
   int rightCameraIndex;//右相机设备索引
   int deviceNum;//相机使用计数，单目or双目
   VideoCapture *m_leftCamera;
   VideoCapture *m_RightCamera;
   QImage left_frame;
   QImage right_frame;
signals:
   void imageCapturesignal();
   void send_leftdispframe(QImage);
   void send_rightdispframe(QImage);
   void send_alldispframe(QImage,QImage);
public slots:
   void accept_leftdeviceIndex(int index);
   void accept_rightdeviceIndex(int index);
   void accept_deviceNum(int);
   void accept_closeLeftCamera();
   void accept_closeRightCamera();
public:
   QImage convertMatToQImage(Mat &mat);
protected:
    void run();
};
#endif // IMAGE_PROCESSTHREAD_H
