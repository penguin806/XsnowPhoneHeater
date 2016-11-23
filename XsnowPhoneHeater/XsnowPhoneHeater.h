#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_XsnowPhoneHeater.h"

class XsnowPhoneHeater : public QMainWindow
{
    Q_OBJECT

public:
    XsnowPhoneHeater(QWidget *parent = Q_NULLPTR);

private:
    Ui::XsnowPhoneHeaterClass ui;
};
