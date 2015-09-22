#include "ejemplo1.h"

ejemplo1::ejemplo1(): Ui_Counter()
{
	setupUi(this);
	show();
	connect(button, SIGNAL(clicked()), this, SLOT(doButton()) );
	connect(&reloj, SIGNAL(timeout()), this, SLOT(suMar()) );
	connect(Slider, SIGNAL(sliderMoved(int)), this, SLOT(aumetarVelocidad()) );
	Slider->setValue(100);
	reloj.setintervalo(200);
	reloj.start();

}

ejemplo1::~ejemplo1()
{}

void ejemplo1::doButton()
{
	qDebug() << "click on button";
	reloj.stop();
	
}
void ejemplo1::suMar()
{
  static int  c=0;
  lcdNumber->display(c++);
  
}
void ejemplo1::aumetarVelocidad()
{
 reloj.setintervalo(Slider->value()*10);
 
}





