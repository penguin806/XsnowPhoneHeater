#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_XsnowPhoneHeater.h"
#include "Thread.h"

#define MAX_THREAD 8

class XsnowPhoneHeater : public QMainWindow
{
    Q_OBJECT

public:
    XsnowPhoneHeater(QWidget *parent = Q_NULLPTR);
    ~XsnowPhoneHeater();
    void GetThreadNumberAndSetLabel();
    void OnRunningDisableControls(bool bRunning);

private slots:
    void onSlideBarValueChanged();
	void onHeatButtonClicked();
	void onCancelButtonClicked();
    void onAboutButtonClicked();

private:
    Ui::XsnowPhoneHeaterClass ui;
    XsnowThread *m_Thread[MAX_THREAD];
	qint8 m_ThreadNumber;
};
