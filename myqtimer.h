#ifndef MYQTIMER_H
#define MYQTIMER_H

#include <qthread.h>
#include <QMutex>
class MyQTimer : public QThread
{
    Q_OBJECT

public:
    MyQTimer();
    MyQTimer(const MyQTimer& other);
 
   

protected:
    virtual void run();

public slots:
  void setintervalo(int intervalo);
  void stop();
      
private:
     //int inter; 
     struct Intervalo
     {
        QMutex mutex;
        int t;
        Intervalo(){ t = 300;};
	void set(int v)
	{
	  QMutexLocker ml(&mutex);
	  t = v;
	}
        int get()
	{
	  QMutexLocker ml(&mutex);
	  return t;
	}
     };
     Intervalo inter;
     
signals: 
  void timeout();
};

#endif // MYQTIMER_H
