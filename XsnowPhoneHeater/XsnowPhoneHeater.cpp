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

    this->ui.label->setText(QString::fromLocal8Bit("线程: ")+
                            QString::number(this->m_ThreadNumber));

    QString Buffer;
    if(this->m_ThreadNumber >= 6)
    {
        Buffer = QString::fromLocal8Bit("超强加热");
    }
    else if(this->m_ThreadNumber >= 2)
    {
        Buffer = QString::fromLocal8Bit("均衡");
    }
    else
    {
        Buffer = QString::fromLocal8Bit("极致性能");
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
                    QString::fromLocal8Bit("已启动线程: ") +
                    QString::number(this->m_ThreadNumber));
    }
    else
    {
        this->ui.label->setText(
                    QString::fromLocal8Bit("线程: ") +
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
               QString::fromLocal8Bit(
                 "请问您是否确定要加热您的爱机?"),
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
    QString Buffer = QString::fromLocal8Bit(
                "xSnow Phone Heater\r\nVersion: 0.1 Alpha\r\n\
Website: www.xsnow.moe\r\n软件采用GPL协议");
    QMessageBox::information(this,"xSnow",Buffer);
}
