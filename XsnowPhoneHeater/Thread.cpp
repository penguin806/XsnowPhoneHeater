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

	do
	{
    //	Mutex.lock();
		if (this->bContinue == false)
		{
            //Mutex.unlock();
			break;
		}
        //Mutex.unlock();
	} while (true);

}

void XsnowThread::stop()
{
    //Mutex.lock();
	this->bContinue = false;
    //Mutex.unlock();
}
