/********************************************************************************
** Form generated from reading UI file 'secondwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include "inc/qcustomplot.hh"

QT_BEGIN_NAMESPACE

class Ui_SecondWindow
{
public:
    QGridLayout *gridLayout;
    QCustomPlot *customPlot;

    void setupUi(QDialog *SecondWindow)
    {
        if (SecondWindow->objectName().isEmpty())
            SecondWindow->setObjectName(QString::fromUtf8("SecondWindow"));
        SecondWindow->resize(554, 477);
        gridLayout = new QGridLayout(SecondWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        customPlot = new QCustomPlot(SecondWindow);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));

        gridLayout->addWidget(customPlot, 0, 0, 1, 1);


        retranslateUi(SecondWindow);

        QMetaObject::connectSlotsByName(SecondWindow);
    } // setupUi

    void retranslateUi(QDialog *SecondWindow)
    {
        SecondWindow->setWindowTitle(QApplication::translate("SecondWindow", "Wykresy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecondWindow: public Ui_SecondWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H
