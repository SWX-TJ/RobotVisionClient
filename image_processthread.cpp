#include "image_processthread.h"
#include <QDebug>
//#include<opencv.hpp>
//#include <vector>
//using namespace cv;
Image_processThread::Image_processThread()
{
    leftCameraIndex = 0;
    rightCameraIndex = 1;
}

void Image_processThread::accept_leftdeviceIndex(int index)
{
    leftCameraIndex = index;
}

void Image_processThread::accept_rightdeviceIndex(int index)
{
    rightCameraIndex = index;
}

void Image_processThread::accept_deviceNum(int usrCameraNum)
{
    deviceNum = usrCameraNum;
}

void Image_processThread::accept_closeLeftCamera()
{
    m_leftCamera->release();
}

void Image_processThread::accept_closeRightCamera()
{
    m_RightCamera->release();
}

QImage Image_processThread::convertMatToQImage(Mat &mat)
{
    QImage img;
    int nChannel=mat.channels();
    if(nChannel==3)
    {
        cvtColor(mat,mat,CV_BGR2RGB);
        img = QImage((const unsigned char*)mat.data,mat.cols,mat.rows,QImage::Format_RGB888);
    }
    else if(nChannel==4||nChannel==1)
    {
        img = QImage((const unsigned char*)mat.data,mat.cols,mat.rows,QImage::Format_ARGB32);
    }

    return img;
}

void Image_processThread::run()
{
  //  Mat imageROI;
   // Mat logo = imread("C:/Users/SWX/Desktop/robot_client/Robot_client/resource/logo.jpg");
    waitKey(30);
    switch (deviceNum) {
    case LEFT_CAMERA:
        m_leftCamera = new VideoCapture(leftCameraIndex);
        while(1)
        {
             Mat frame,dst_frame,resize_frame;
            m_leftCamera->operator >>(frame);
            /**********/
            //TODO opencv to qt显示
            dst_frame = frame.clone();
            resize(dst_frame,resize_frame,Size(320,240));
            left_frame = convertMatToQImage(resize_frame);
            send_leftdispframe(left_frame);
            /**********/
            /**********/
             //TODO 图像处理区域

            /**********/
            imshow("left_video",frame);
            waitKey(30);
        }
        break;
    case RIGHT_CAMERA:
        m_RightCamera = new VideoCapture(rightCameraIndex);
        while(1)
        {
            Mat frame,dst_frame,resize_frame;
            m_RightCamera->operator >>(frame);
            dst_frame = frame.clone();
            resize(dst_frame,resize_frame,Size(320,240));
            right_frame = convertMatToQImage(resize_frame);
            send_rightdispframe(right_frame);
            imshow("right_video",frame);
            waitKey(30);
        }
        break;
    case ALL_CAMERA:
        m_leftCamera = new VideoCapture(leftCameraIndex);
        m_RightCamera = new VideoCapture(rightCameraIndex);
        while(1)
        {
            Mat left_ori_frame,right_ori_frame,left_dst_frame,right_dst_frame,left_resize_frame,right_resize_frame,mix_frame;
            m_leftCamera->operator >>(left_ori_frame);
            m_RightCamera->operator >>(right_ori_frame);
            left_dst_frame = left_ori_frame.clone();
            right_dst_frame = right_ori_frame.clone();
            resize(left_dst_frame,left_resize_frame,Size(320,240));
            resize(right_dst_frame,right_resize_frame,Size(320,240));
            left_frame = convertMatToQImage(left_resize_frame);
            right_frame = convertMatToQImage(right_resize_frame);
            send_alldispframe(left_frame,right_frame);
            /**********/
             //TODO 图像处理区域
    //addWeighted(left_ori_frame,0.8,right_ori_frame,0.2,0,mix_frame);
            /**********/
             imshow("mix_frame",mix_frame);
            //imshow("right_video",right_ori_frame);
            waitKey(30);
        }
        break;
    default:
        break;
    }
}
