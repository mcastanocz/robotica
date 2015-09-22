#include "myqtimer.h"

MyQTimer::MyQTimer()
{
}

MyQTimer::MyQTimer(const MyQTimer& other)
{
}

void MyQTimer::run()
{
  while(true)
  {
   msleep(inter.get());
   emit timeout();
  }
  
}
void MyQTimer::setintervalo(int intervalo)
{
  inter.set(intervalo);
}

void MyQTimer::stop()
{
this->terminate();
}

