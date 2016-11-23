#pragma once
#include <QThread>
//#include <QMutex>

//extern QMutex Mutex;

class XsnowThread : public QThread
{
public:
	XsnowThread();
    ~XsnowThread();
	void run();
	void stop();

private:
	volatile bool bContinue;
};
