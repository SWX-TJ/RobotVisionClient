#ifndef REGISTER_DIALOG_H
#define REGISTER_DIALOG_H

#include <QDialog>

namespace Ui {
class Register_Dialog;
}

class Register_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Register_Dialog(QWidget *parent = 0);
    ~Register_Dialog();

private slots:
    void on_exit_btn_clicked();
private:
    Ui::Register_Dialog *ui;
};

#endif // REGISTER_DIALOG_H
