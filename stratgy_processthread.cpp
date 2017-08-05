#include "stratgy_processthread.h"
#include <QDebug>
Stratgy_processThread::Stratgy_processThread()
{

}

void Stratgy_processThread::run()
{
    //测试用函数
    while(1)
    {
        qDebug()<<"this is from strategy_thread"<<endl;
    }
}
