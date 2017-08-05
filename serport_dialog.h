#ifndef SERPORT_DIALOG_H
#define SERPORT_DIALOG_H

#include <QDialog>

namespace Ui {
class serport_Dialog;
}

class serport_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit serport_Dialog(QWidget *parent = 0);
    ~serport_Dialog();
signals:
    void returnSignal(int);
private slots:
    void on_return_btn_clicked();
    void on_openSerport_btn_clicked();
private:
    Ui::serport_Dialog *ui;
};

#endif // SERPORT_DIALOG_H
