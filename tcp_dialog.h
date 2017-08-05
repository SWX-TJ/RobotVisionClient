#ifndef TCP_DIALOG_H
#define TCP_DIALOG_H
#include <QDialog>
namespace Ui {
class Tcp_Dialog;
}

class Tcp_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Tcp_Dialog(QWidget *parent = 0);
    ~Tcp_Dialog();
signals:
    void returnSignal(int);//返回主界面函数
private slots:
    void on_Connect_btn_clicked();
    void on_Return_btn_clicked();
private:
    Ui::Tcp_Dialog *ui;
};

#endif // TCP_DIALOG_H
