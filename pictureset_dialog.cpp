#include "pictureset_dialog.h"
#include "ui_pictureset_dialog.h"

PictureSet_Dialog::PictureSet_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PictureSet_Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("图像设置"));
    this->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
}

PictureSet_Dialog::~PictureSet_Dialog()
{
    delete ui;
}

void PictureSet_Dialog::on_R_channelSlider_sliderMoved(int position)
{
    QString R_channelValue;
    ui->R_channelDisp->setText(R_channelValue.setNum(position));
}

void PictureSet_Dialog::on_G_channerlSlider_sliderMoved(int position)
{
    QString G_channelValue;
    ui->G_channelDisp->setText(G_channelValue.setNum(position));
}

void PictureSet_Dialog::on_B_channelSlider_sliderMoved(int position)
{
    QString B_channelValue;
    ui->B_channelDisp->setText(B_channelValue.setNum(position));
}

void PictureSet_Dialog::on_ReturnBtn_clicked()
{
         returnSignal(5);
}

void PictureSet_Dialog::on_contrastSlider_sliderMoved(int position)
{
    QString ContrastValue;
    ui->contrastDisp->setText(ContrastValue.setNum(position));
}

void PictureSet_Dialog::on_brightSlider_sliderMoved(int position)
{
    QString brightValue;
    ui->brightDisp->setText(brightValue.setNum(position));
}
