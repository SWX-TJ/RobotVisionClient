#include "image_processthread.h"
#include <QDebug>
//#include<opencv.hpp>
#include <vector>
#include <iostream>
using namespace cv;
using namespace  std;
Image_processThread::Image_processThread()
{
    leftCameraIndex = 0;
    rightCameraIndex = 1;
    R_Gen = 1.0;
    G_Gen = 1.0;
    B_Gen = 1.0;
    Contrast_Gen = 100;
    Bright_Gen = 0;
    AutoWhiteBalance = false;

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

void Image_processThread::accept_RGBGen(int r, int g, int b)
{
    R_Gen += double(r)/100;
    G_Gen += double(g)/100;
    B_Gen += double(b)/100;
}

void Image_processThread::accept_ContrastBrightGen(int contrast, int bright)
{
    Contrast_Gen += contrast;
    Bright_Gen   += bright;
   // qDebug()<<"Contrast_Gen"<<Contrast_Gen<<" Bright_Gen "<<Bright_Gen<<endl;
}

void Image_processThread::accept_AutoWhiteBalance()
{
    AutoWhiteBalance = true;
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

Mat Image_processThread::contrastAndBrightSet(Mat &frame, int contrastValue, int BrightValue)
{
    Mat preset_frame;
     preset_frame = frame.clone();
    for(int y =0;y<frame.rows;y++)
    {
        for(int x =0;x<frame.cols;x++)
        {
            for(int c=0;c<3;c++)
            {
                 preset_frame.at<Vec3b>(y,x)[c] = saturate_cast<uchar>((contrastValue*0.01)*frame.at<Vec3b>(y,x)[c]+BrightValue);
            }
        }
    }

    return preset_frame;
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
            if(!AutoWhiteBalance)
            {
                Mat frame,preset_frame,dst_frame,resize_frame;vector<Mat>imageBGR;
                m_leftCamera->operator >>(frame);
                /**/
                //TODO 图像处理区域
                split(frame,imageBGR);
                imageBGR[0] = imageBGR[0]*B_Gen;
                imageBGR[1] = imageBGR[1]*G_Gen;
                imageBGR[2] = imageBGR[2]*R_Gen;
                merge(imageBGR,frame);
                preset_frame= contrastAndBrightSet(frame,Contrast_Gen,Bright_Gen);
                /**/
                /**********/
                //TODO opencv to qt显示

                dst_frame = preset_frame.clone();
                resize(dst_frame,resize_frame,Size(320,240));
                left_frame = convertMatToQImage(resize_frame);
                send_leftdispframe(left_frame);
                /**********/
                /**********/
                //TODO 图像测试处理区域


                /**********/
                imshow("left_video",preset_frame);
                waitKey(30);
            }
            else
            {
                 AutoWhiteBalance = !AutoWhiteBalance;
                Mat frame,preset_frame,dst_frame,resize_frame;vector<Mat>imageBGR;
                m_leftCamera->operator >>(frame);
                /**/
                //TODO 图像处理区域
                split(frame,imageBGR);
                double R_BalanceValue, G_BalanceValue, B_BalanceValue;
                B_BalanceValue = mean(imageBGR[0])[0];
                G_BalanceValue = mean(imageBGR[1])[0];
                R_BalanceValue = mean(imageBGR[2])[0];
                double KR, KG, KB;
                KB = (R_BalanceValue + G_BalanceValue + B_BalanceValue) / (3 * B_BalanceValue);
                KG = (R_BalanceValue + G_BalanceValue+ B_BalanceValue) / (3 * G_BalanceValue);
                KR = (R_BalanceValue + G_BalanceValue + B_BalanceValue) / (3 * R_BalanceValue);
                R_Gen =  KR;
                G_Gen =  KG;
                B_Gen =  KB;
                imageBGR[0] = imageBGR[0]*KB;
                imageBGR[1] = imageBGR[1]*KG;
                imageBGR[2] = imageBGR[2]*KR;
                merge(imageBGR,frame);
                 preset_frame= contrastAndBrightSet(frame,Contrast_Gen,Bright_Gen);
                /**/
                /**********/
                //TODO opencv to qt显示

                dst_frame =  preset_frame.clone();
                resize(dst_frame,resize_frame,Size(320,240));
                left_frame = convertMatToQImage(resize_frame);
                send_leftdispframe(left_frame);
                /**********/
                /**********/
                //TODO 图像测试处理区域


                /**********/
                imshow("left_video", preset_frame);
                waitKey(30);
            }
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
