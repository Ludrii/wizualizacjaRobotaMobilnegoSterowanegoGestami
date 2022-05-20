#ifndef SECONDWINDOW_HH
#define SECONDWINDOW_HH

#include <QDialog>
#include <QTime>
#include <QSerialPort>
#include <array>
#include <iostream>
#include <QDebug>
#include <QCoreApplication>
#include "inc/odbior.hh"

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();
    std::array<int,4> *wData = nullptr;
    QSerialPort *wSerial = nullptr;
    void setArray(std::array<int,4> *wArray) { wData = wArray; }
    void setSerial(QSerialPort *_wSerial) { wSerial = _wSerial; }
    void makePlot();

private slots:
    void realtimeDataSlot();
private:
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_HH
