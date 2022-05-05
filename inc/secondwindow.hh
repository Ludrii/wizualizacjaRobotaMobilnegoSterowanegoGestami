#ifndef SECONDWINDOW_HH
#define SECONDWINDOW_HH

#include <QDialog>
#include <QTime>
#include <QtSerialPort/QSerialPort>
#include <array>
#include <iostream>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private slots:
    void makePlot();
    void realtimeDataSlot();
private:
    Ui::SecondWindow *ui;
    QSerialPort serial;
};

#endif // SECONDWINDOW_HH
