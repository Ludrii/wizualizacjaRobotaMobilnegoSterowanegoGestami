#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include "inc/odbior.hh"
#include <QLCDNumber>
#include <QThread>
#include <QBrush>
#include <QtGui>
#include <QtCore>
#include <QDialog>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Komunikacja  *_wLacze = nullptr;
    QSerialPort serial;
    QTimer *timer;
    std::array<int,4>  data;
    void UstawLacze(Komunikacja *wLaczeKom) { _wLacze = wLaczeKom; }

private slots:
    void on_pushButton_clicked();
    void lcdNumber();
    void openSerialPort();
    void getData();
    void progressBar();
    void greenLedOn();
    void draw();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem *rect0;
    QGraphicsRectItem *rect1;
    QGraphicsRectItem *rect2;
    QGraphicsRectItem *rect3;
};
#endif // MAINWINDOW_HH
