#ifndef STRATGY_PROCESSTHREAD_H
#define STRATGY_PROCESSTHREAD_H
#include <QObject>
#include <QThread>
class Stratgy_processThread : public QThread
{
    Q_OBJECT
public:
  Stratgy_processThread();
protected:
  void run();
};

#endif // STRATGY_PROCESSTHREAD_H
