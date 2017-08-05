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
    int r_ChannelValue;
    int g_ChannelValue;
    int b_ChannelValue;
signals:
    void returnSignal(int);
private slots:
    void on_R_channelSlider_sliderMoved(int position);
    void on_G_channerlSlider_sliderMoved(int position);
    void on_B_channelSlider_sliderMoved(int position);
    void on_ReturnBtn_clicked();

    void on_contrastSlider_sliderMoved(int position);

    void on_brightSlider_sliderMoved(int position);

private:
    Ui::PictureSet_Dialog *ui;
};

#endif // PICTURESET_DIALOG_H
