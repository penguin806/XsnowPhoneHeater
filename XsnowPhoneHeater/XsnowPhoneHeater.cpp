#include "XsnowPhoneHeater.h"
#include <QMessageBox>
#include <qDebug>

XsnowPhoneHeater::XsnowPhoneHeater(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

    this->m_ThreadNumber = 0;
    this->ui.horizontalSlider->setValue(1);
    this->GetThreadNumberAndSetLabel();
    this->OnRunningDisableControls(false);

    for(int i=0;i<MAX_THREAD;i++)
    {
        this->m_Thread[i] = nullptr;
    }

    QObject::connect(this->ui.pushButton,SIGNAL(clicked(bool)),
            this,SLOT(onHeatButtonClicked()));

    QObject::connect(this->ui.pushButton_2,SIGNAL(clicked(bool)),
            this,SLOT(onCancelButtonClicked()));

    QObject::connect(this->ui.pushButton_3,SIGNAL(clicked(bool)),
            this,SLOT(onAboutButtonClicked()));

    QObject::connect(this->ui.horizontalSlider,
            SIGNAL(valueChanged(int)),this,SLOT(onSlideBarValueChanged()));
}

XsnowPhoneHeater::~XsnowPhoneHeater()
{
    for(int i=0;i<this->m_ThreadNumber;i++)
    {
        if(this->m_Thread[i])
        {
            this->m_Thread[i]->stop();
            this->m_Thread[i]->wait(5);
            delete this->m_Thread[i];
        }
    }

    this->OnRunningDisableControls(false);
}

void XsnowPhoneHeater::GetThreadNumberAndSetLabel()
{
    this->m_ThreadNumber = this->ui.horizontalSlider->value();

    this->ui.label->setText(TEXT("线程: ")+
                            QString::number(this->m_ThreadNumber));

    QString Buffer;
    if(this->m_ThreadNumber >= 16)
    {
        Buffer = TEXT("Boom!");
    }
    else if(this->m_ThreadNumber >= 6)
    {
        Buffer = TEXT("超强加热");
    }
    else if(this->m_ThreadNumber >= 2)
    {
        Buffer = TEXT("均衡");
    }
    else
    {
        Buffer = TEXT("极致性能");
    }
    this->ui.label_2->setText(Buffer);
}

void XsnowPhoneHeater::onSlideBarValueChanged()
{
    this->GetThreadNumberAndSetLabel();
}

void XsnowPhoneHeater::OnRunningDisableControls(bool bRunning)
{
    this->ui.horizontalSlider->setDisabled(bRunning);

    if(bRunning)
    {
        this->ui.label->setText(
                    TEXT("已启动线程: ") +
                    QString::number(this->m_ThreadNumber));
    }
    else
    {
        this->ui.label->setText(
                    TEXT("线程: ") +
                    QString::number(this->m_ThreadNumber));
    }

    this->ui.label->setDisabled(bRunning);

    this->ui.label_2->setDisabled(bRunning);
    this->ui.pushButton->setDisabled(bRunning);
    this->ui.pushButton_2->setDisabled(!bRunning);
}

void XsnowPhoneHeater::onHeatButtonClicked()
{
    int Result;

    Result = QMessageBox::question(this,"xSnow",
                 TEXT("您确定要开始加热吗?"),
               QMessageBox::Yes, QMessageBox::No);

    if(Result == QMessageBox::No)
        return;

    Result = QMessageBox::question(this,"Confirm",
                 TEXT("请问您真的确定吗?"),
               QMessageBox::Yes, QMessageBox::No);

    if(Result == QMessageBox::No)
        return;


    this->GetThreadNumberAndSetLabel();
    this->OnRunningDisableControls(true);

    if(this->m_ThreadNumber <= 0 ||
            this->m_ThreadNumber > MAX_THREAD)
    {
        QMessageBox::critical(this,"xSnow",
                              "Critical Error");
        qApp->quit();
        return;
    }

    //qDebug() << this->m_ThreadNumber;

    for(int i=0;i<this->m_ThreadNumber;i++)
    {
        this->m_Thread[i] = new XsnowThread();
        this->m_Thread[i]->start();
    }

}

void XsnowPhoneHeater::onCancelButtonClicked()
{
    for(int i=0;i<this->m_ThreadNumber;i++)
    {
        if(this->m_Thread[i])
        {
            this->m_Thread[i]->stop();
            this->m_Thread[i]->wait(5);
            delete this->m_Thread[i];
        }
    }
    this->OnRunningDisableControls(false);
}

void XsnowPhoneHeater::onAboutButtonClicked()
{
    QString Buffer = TEXT("xSnow Phone Heater\r\nVersion: 0.2 Alpha\r\n\
Website: www.xsnow.moe\r\n软件采用GPL协议\r\n\
Tips: 线程数与发热效率成正比, 与系统流畅度反比, \
请根据CPU核心数调整\r\nNOTE7用户慎用!!!\r\n");
    QMessageBox::information(this,"xSnow",Buffer);
}
