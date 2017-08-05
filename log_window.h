#ifndef LOG_WINDOW_H
#define LOG_WINDOW_H
#include "client_mainwindow.h"
#include "register_dialog.h"
#include <QDialog>
namespace Ui {
class Log_window;
}

class Log_window : public QDialog
{
    Q_OBJECT
public:
    explicit Log_window(QWidget *parent = 0);
    ~Log_window();
private slots:
    void on_log_btn_clicked();
    void on_exit_btn_clicked();
    void on_register_btn_clicked();
public:
    Client_mainwindow *m_client;
    Register_Dialog *m_register;
private:
    Ui::Log_window *ui;
};

#endif // LOG_WINDOW_H
