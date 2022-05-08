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
    Komunikacja  *_wLacze = nullptr;
    QSerialPort serial;
    QTimer *timer;
    void UstawLacze(Komunikacja *wLaczeKom) { _wLacze = wLaczeKom; }

private slots:
    void openSerialPort();
    void makePlot();
    void realtimeDataSlot();
private:
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_HH
