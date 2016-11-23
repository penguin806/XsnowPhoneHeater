#include "XsnowPhoneHeater.h"
#include "Thread.h"
#include <QtWidgets/QApplication>

//QMutex Mutex;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XsnowPhoneHeater w;
    w.show();
    return a.exec();
}
