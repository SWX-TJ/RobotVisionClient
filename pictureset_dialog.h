#ifndef PICTURESET_DIALOG_H
#define PICTURESET_DIALOG_H

#include <QDialog>

namespace Ui {
class PictureSet_Dialog;
}

class PictureSet_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit PictureSet_Dialog(QWidget *parent = 0);
    ~PictureSet_Dialog();
public:
    int r_ChannelValue;//r_通道滑动条当前值
    int g_ChannelValue;//g_通道滑动条当前值
    int b_ChannelValue;//b_通道滑动条当前值
    int r_LastChannelValue;//r_通道滑动条上一时刻值
    int g_LastChannelValue;//g_通道滑动条上一时刻值
    int b_LastChannelValue;//b_通道滑动条上一时刻值
    int r_SendChannelValue;//r_发送值
    int g_SendChannelValue;//g_发送值
    int b_SendChannelValue;//b_发送值
    int contrastValue;
    int brightValue;
    bool r_sliderEnable;//r_通道滑动条触发状态变量
    bool g_sliderEnable;//g_通道滑动条触发状态变量
    bool b_sliderEnable;//b_通道滑动条触发状态变量
signals:
    void returnSignal(int);
    void sendSignalAutoWhiteBalance();
    void send_RGBGen(int,int,int);
private slots:
    void on_R_channelSlider_sliderMoved(int position);
    void on_G_channerlSlider_sliderMoved(int position);
    void on_B_channelSlider_sliderMoved(int position);
    void on_ReturnBtn_clicked();
    void on_contrastSlider_sliderMoved(int position);
    void on_brightSlider_sliderMoved(int position);
    void on_WhiteBalanceBtn_clicked();
    void on_SetBtn_clicked();

private:
    Ui::PictureSet_Dialog *ui;
};

#endif // PICTURESET_DIALOG_H
