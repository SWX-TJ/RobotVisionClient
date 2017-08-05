#ifndef CLIENT_MAINWINDOW_H
#define CLIENT_MAINWINDOW_H
#include <QMainWindow>
#include <QImage>
#include "serport_dialog.h"
#include "tcp_dialog.h"
#include "image_processthread.h"
#include "stratgy_processthread.h"
#include "camerasetting_dialog.h"
#include "goaldetection_dialog.h"
#include "pictureset_dialog.h"
#define SERPORTWINDOW_NUM       1
#define TCPSERVERWINDOW_NUM     2
#define CAMERASETTINGWINDOW_NUM 3
#define GOALDETECTWINDOW_NUM    4
#define PICTURESETWINDOW_NUM    5
namespace Ui {
class Client_mainwindow;
}

class Client_mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client_mainwindow(QWidget *parent = 0);
    ~Client_mainwindow();
public:
    serport_Dialog          *m_serport;
    Tcp_Dialog              *m_tcpserver;
    CameraSetting_Dialog    *m_camset;
    Image_processThread     *m_image_thread;
    Stratgy_processThread   *m_stratgy_thread;
    GoalDetection_Dialog    *m_goalDetect;
    PictureSet_Dialog       *m_pictureSet;
    int UseWhichCamera;
    bool LoadCameraBtnState;
    bool LoadStratgyBtnState;
signals:
    void close_leftCamera();
    void close_rightCamera();
private slots:
    void shutSlaveWindowSlot(int);
    void on_actioncklj_triggered();
    void on_actionfwqlj_triggered();
    void on_openCamera_btn_clicked();
    void on_load_dll_btn_clicked();
    void on_stop_btn_clicked();
    void on_camera_Set_triggered();
    void acept_UseCameraNum(int);
    void accept_leftdispFrame(QImage);
    void accept_rightdispFrame(QImage);
    void accept_alldispFrame(QImage,QImage);
    void on_destination_Set_triggered();
    void on_pictureSet_triggered();

private:
    Ui::Client_mainwindow *ui;
};

#endif // CLIENT_MAINWINDOW_H
