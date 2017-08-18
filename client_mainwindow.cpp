#include "client_mainwindow.h"
#include "ui_client_mainwindow.h"
#include <QMessageBox>
Client_mainwindow::Client_mainwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client_mainwindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("双足机器人客户端"));
    UseWhichCamera = 0;
    LoadCameraBtnState = false;
    LoadStratgyBtnState = false;
    m_serport          = new serport_Dialog(this);
    m_tcpserver        = new Tcp_Dialog(this);
    m_camset           = new CameraSetting_Dialog(this);
    m_stratgy_thread   = new Stratgy_processThread();
    m_image_thread     = new Image_processThread();
    m_goalDetect       = new GoalDetection_Dialog;
    m_pictureSet       = new PictureSet_Dialog;
    connect(m_pictureSet,SIGNAL(returnSignal(int)),this,SLOT(shutSlaveWindowSlot(int)));
    connect(m_goalDetect,SIGNAL(returnSignal(int)),this,SLOT(shutSlaveWindowSlot(int)));
    connect(m_goalDetect,SIGNAL(send_RobotMode(int)),m_image_thread,SLOT(accept_RobotMode(int)));
    connect(this,SIGNAL(close_leftCamera()),m_image_thread,SLOT(accept_closeLeftCamera()));
    connect(this,SIGNAL(close_rightCamera()),m_image_thread,SLOT(accept_closeRightCamera()));
    connect(m_image_thread,SIGNAL(send_alldispframe(QImage,QImage)),this,SLOT(accept_alldispFrame(QImage,QImage)));
    connect(m_image_thread,SIGNAL(send_leftdispframe(QImage)),this,SLOT(accept_leftdispFrame(QImage)));
    connect(m_image_thread,SIGNAL(send_rightdispframe(QImage)),this,SLOT(accept_rightdispFrame(QImage)));
    connect(m_serport,SIGNAL(returnSignal(int)),this,SLOT(shutSlaveWindowSlot(int)));
    connect(m_tcpserver,SIGNAL(returnSignal(int)),this,SLOT(shutSlaveWindowSlot(int)));
    connect(m_camset,SIGNAL(returnSignal(int)),this,SLOT(shutSlaveWindowSlot(int)));
    connect(m_camset,SIGNAL(send_UseCameraNum(int)),this,SLOT(acept_UseCameraNum(int)));
    connect(m_camset,SIGNAL(send_leftdeviceIndex(int)),m_image_thread,SLOT(accept_leftdeviceIndex(int)));
    connect(m_camset,SIGNAL(send_rightdeviceIndex(int)),m_image_thread,SLOT(accept_rightdeviceIndex(int)));
    connect(m_camset,SIGNAL(send_UseCameraNum(int)),m_image_thread,SLOT(accept_deviceNum(int)));
    connect(m_pictureSet,SIGNAL(send_RGBGen(int,int,int)),m_image_thread,SLOT(accept_RGBGen(int,int,int)));
    connect(m_pictureSet,SIGNAL(sendSignalAutoWhiteBalance()),m_image_thread,SLOT(accept_AutoWhiteBalance()));
    connect(m_pictureSet,SIGNAL(send_ContrastAndBright(int,int)),m_image_thread,SLOT(accept_ContrastBrightGen(int,int)));
}

Client_mainwindow::~Client_mainwindow()
{
    delete ui;
}

void Client_mainwindow::shutSlaveWindowSlot(int window_num)
{
    switch (window_num) {
    case SERPORTWINDOW_NUM:
        m_serport->close();
        break;
    case TCPSERVERWINDOW_NUM:
        m_tcpserver->close();
        break;
    case CAMERASETTINGWINDOW_NUM:
        m_camset->close();
        break;
    case GOALDETECTWINDOW_NUM:
        m_goalDetect->close();
        break;
    case PICTURESETWINDOW_NUM:
        m_pictureSet->close();
        break;
    default:
        break;
    }
}

void Client_mainwindow::on_actioncklj_triggered()
{
    m_serport->show();
}

void Client_mainwindow::on_actionfwqlj_triggered()
{
    m_tcpserver->show();
}

void Client_mainwindow::on_openCamera_btn_clicked()
{

    //执行图像处理线程A
    LoadCameraBtnState = !LoadCameraBtnState;
    if(LoadCameraBtnState)
    {

        switch (UseWhichCamera) {
        case LEFT_CAMERA:
            m_image_thread->start();

            ui->openCamera_btn->setText("关闭视觉");
            break;
        case RIGHT_CAMERA:
            m_image_thread->start();
            ui->openCamera_btn->setText("关闭视觉");
            break;
        case ALL_CAMERA:
            m_image_thread->start();
            ui->openCamera_btn->setText("关闭视觉");
            break;
        default:
            QMessageBox::information(this,"摄像头加载","没有摄像头设备或者没有设置摄像头");
            LoadCameraBtnState = !LoadCameraBtnState;
            break;
        }

    }
    else
    {
        switch (UseWhichCamera) {
        case LEFT_CAMERA:
            emit close_leftCamera();
            m_image_thread->terminate();
            m_image_thread->wait();
            ui->openCamera_btn->setText("加载视觉");
            break;
        case RIGHT_CAMERA:
            emit close_rightCamera();
            m_image_thread->terminate();
            m_image_thread->wait();
            ui->openCamera_btn->setText("加载视觉");
            break;
        case ALL_CAMERA:
            emit close_leftCamera();
            emit close_rightCamera();
            m_image_thread->terminate();
            m_image_thread->wait();
            ui->openCamera_btn->setText("加载视觉");
            break;
        default:
            QMessageBox::information(this,"关闭视觉","摄像头关闭错误，请重新关闭或者结束进程");
            LoadCameraBtnState = !LoadCameraBtnState;
            break;
        }


    }
}

void Client_mainwindow::on_load_dll_btn_clicked()
{
    //执行逻辑策略线程B
    LoadStratgyBtnState = !LoadStratgyBtnState;
    if(LoadStratgyBtnState)
    {
        ui->load_dll_btn->setText("停止执行");
        m_stratgy_thread->start();

    }
    else
    {
        ui->load_dll_btn->setText("加载策略");
        m_stratgy_thread->terminate();
        m_stratgy_thread->wait();
    }
}

void Client_mainwindow::on_stop_btn_clicked()
{
    exit(EXIT_SUCCESS);

}

void Client_mainwindow::on_camera_Set_triggered()
{
    m_camset->show();

}

void Client_mainwindow::acept_UseCameraNum(int cameraFlag)
{
    UseWhichCamera  = cameraFlag;
}

void Client_mainwindow::accept_leftdispFrame(QImage left_frame)
{
    ui->left_cameradisp->setPixmap(QPixmap::fromImage(left_frame));
}

void Client_mainwindow::accept_rightdispFrame(QImage right_frame)
{
    ui->right_cameradisp->setPixmap(QPixmap::fromImage(right_frame));
}

void Client_mainwindow::accept_alldispFrame(QImage left_frame, QImage right_frame)
{
    ui->left_cameradisp->setPixmap(QPixmap::fromImage(left_frame));
    ui->right_cameradisp->setPixmap(QPixmap::fromImage(right_frame));

}
void Client_mainwindow::on_destination_Set_triggered()
{
    m_goalDetect->show();
}

void Client_mainwindow::on_pictureSet_triggered()
{
    m_pictureSet->show();
}
