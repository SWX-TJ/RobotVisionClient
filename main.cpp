#include <QApplication>
#include "log_window.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Log_window w;
    w.show();

    return a.exec();
}
