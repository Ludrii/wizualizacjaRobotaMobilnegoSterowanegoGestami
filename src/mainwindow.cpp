#include "inc/mainwindow.hh"
#include "ui_mainwindow.h"
#include "inc/secondwindow.hh"
#include "inc/qcustomplot.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer;
    QTimer::singleShot(1000,this, SLOT(openSerialPort()));
    connect(&serial, SIGNAL(readyRead()), this, SLOT(getData()));
    connect(&serial, SIGNAL(readyRead()), this, SLOT(lcdNumber()));
    connect(&serial, SIGNAL(readyRead()), this, SLOT(progressBar()));
}

MainWindow::~MainWindow()
{
    delete ui;
    serial.close();
}


void MainWindow::on_pushButton_clicked()
{
    SecondWindow sW(this);
    sW.setModal(true);
    sW.setArray(&data);
    sW.setSerial(&serial);
    sW.makePlot();
    sW.exec();
}

void MainWindow::lcdNumber()
{
    ui->lcdNumber->display(10*data.at(0));
}

void MainWindow::openSerialPort()
{
    _wLacze->SkojarzObiektPortu(&serial);

    serial.setBaudRate(QSerialPort::Baud115200);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setPortName(QString::fromStdString(_wLacze->_NazwaPortu));

    if(!serial.open(QSerialPort::ReadOnly))
    {
        std::cerr << ":( Blad otwarcia portu " << _wLacze->_NazwaPortu << std::endl;
    }
    else
    {
        greenLedOn();
    }
}

void MainWindow::getData()
{
    const QByteArray byteArray = serial.readAll();
    const QString string(byteArray);
    QStringList list;

    list=string.split(QRegExp("\\s+"));

    for(int i=0;i<4;i++)
    {
        data.at(i)=list.at(i).toInt();
    }
}

void MainWindow::progressBar()
{
    ui->progressBar->setValue(10*data.at(1));
}

void MainWindow::greenLedOn()
{
    ui->led->setPixmap(QPixmap("../img/led/led_green.png"));
}
