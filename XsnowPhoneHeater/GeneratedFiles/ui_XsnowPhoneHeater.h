/********************************************************************************
** Form generated from reading UI file 'XsnowPhoneHeater.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XSNOWPHONEHEATER_H
#define UI_XSNOWPHONEHEATER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XsnowPhoneHeaterClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *XsnowPhoneHeaterClass)
    {
        if (XsnowPhoneHeaterClass->objectName().isEmpty())
            XsnowPhoneHeaterClass->setObjectName(QStringLiteral("XsnowPhoneHeaterClass"));
        XsnowPhoneHeaterClass->resize(363, 645);
        centralWidget = new QWidget(XsnowPhoneHeaterClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(20, 60, 20, 30);
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy);
        horizontalSlider->setMinimumSize(QSize(0, 0));
        horizontalSlider->setMaximumSize(QSize(16777215, 40));
        horizontalSlider->setBaseSize(QSize(0, 0));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(20);
        horizontalSlider->setPageStep(1);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 0, 0, 1, 2);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 3, 0, 1, 2);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 6, 0, 1, 2);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 2, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Ignored);

        gridLayout->addItem(verticalSpacer_2, 4, 0, 1, 2);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Ignored);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 2);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 5, 1, 1, 1);

        XsnowPhoneHeaterClass->setCentralWidget(centralWidget);

        retranslateUi(XsnowPhoneHeaterClass);

        QMetaObject::connectSlotsByName(XsnowPhoneHeaterClass);
    } // setupUi

    void retranslateUi(QMainWindow *XsnowPhoneHeaterClass)
    {
        XsnowPhoneHeaterClass->setWindowTitle(QApplication::translate("XsnowPhoneHeaterClass", "XsnowPhoneHeater", 0));
        label_2->setText(QApplication::translate("XsnowPhoneHeaterClass", "TextLabel", 0));
        pushButton_3->setText(QApplication::translate("XsnowPhoneHeaterClass", "\345\205\263\344\272\216", 0));
        label->setText(QApplication::translate("XsnowPhoneHeaterClass", "TextLabel", 0));
        pushButton->setText(QApplication::translate("XsnowPhoneHeaterClass", "\345\212\240\347\203\255", 0));
        pushButton_2->setText(QApplication::translate("XsnowPhoneHeaterClass", "\345\201\234\346\255\242", 0));
    } // retranslateUi

};

namespace Ui {
    class XsnowPhoneHeaterClass: public Ui_XsnowPhoneHeaterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XSNOWPHONEHEATER_H
