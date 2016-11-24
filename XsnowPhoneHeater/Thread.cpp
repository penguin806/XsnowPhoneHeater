#include "Thread.h"

XsnowThread::XsnowThread()
{
    //Mutex.lock();
	this->bContinue = true;
    //Mutex.unlock();
}

XsnowThread::~XsnowThread()
{
    //Mutex.lock();
    this->bContinue = false;
    //Mutex.unlock();
}

void XsnowThread::run()
{
	//QMutexLocker Lock(&Mutex);

    // v0.2 Alpha: 增加浮点运算
    double Temp = 1.1;
	do
	{
    //	Mutex.lock();
		if (this->bContinue == false)
		{
            //Mutex.unlock();
			break;
		}
        Temp*=Temp;
        //Mutex.unlock();
	} while (true);

}

void XsnowThread::stop()
{
    //Mutex.lock();
	this->bContinue = false;
    //Mutex.unlock();
}
