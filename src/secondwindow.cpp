#include "inc/secondwindow.hh"
#include "ui_secondwindow.h"
#include "inc/odbior.hh"

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    //SecondWindow::openSerialPort();
    //SecondWindow::makePlot();
    timer = new QTimer;
    QTimer::singleShot(1000,this, SLOT(makePlot()));
}

SecondWindow::~SecondWindow()
{
    delete ui;
    serial.close();
}

void SecondWindow::makePlot()
{
    openSerialPort();

    ui->customPlot->legend->setVisible(true);
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setPen(QPen(QColor(255, 0, 0)));
    ui->customPlot->graph(0)->setName("Czujnik 1.");
    ui->customPlot->addGraph();
    ui->customPlot->graph(1)->setPen(QPen(QColor(0, 255, 0)));
    ui->customPlot->graph(1)->setName("Czujnik 2.");
    ui->customPlot->addGraph();
    ui->customPlot->graph(2)->setPen(QPen(QColor(0, 0, 255)));
    ui->customPlot->graph(2)->setName("Czujnik 3.");
    ui->customPlot->addGraph();
    ui->customPlot->graph(3)->setName("Czujnik 4.");
    ui->customPlot->graph(3)->setPen(QPen(QColor(0, 0, 0)));

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%m:%s");
    ui->customPlot->xAxis->setTicker(timeTicker);
    ui->customPlot->axisRect()->setupFullAxesBox();

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));

    // setup a timer that repeatedly calls *Window::realtimeDataSlot:
    connect(&serial, SIGNAL(readyRead()), this, SLOT(realtimeDataSlot()));
}

void SecondWindow::realtimeDataSlot()
{
    //qDebug()<<"Czy ja tu wgle wchodze?";
    static QTime time(QTime::currentTime());
    // calculate two new data points:
    double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
    std::array<int,4>  data;
    const QByteArray byteArray = serial.readAll();
    const QString string(byteArray);
    QStringList list;

    list=string.split(QRegExp("\\s+"));

    for(int i=0;i<4;i++)
    {
        data.at(i)=list.at(i).toInt();
        // add data to lines:
        ui->customPlot->graph(i)->addData(key, data.at(i));
        // rescale value (vertical) axis to fit the current data:
        ui->customPlot->graph(i)->rescaleValueAxis(true);
        //qDebug()<<data.at(i);
    }

    // make key axis range scroll with the data (at a constant range size of 8):
    ui->customPlot->xAxis->setRange(key, 8, Qt::AlignRight);
    ui->customPlot->replot();
}

void SecondWindow::openSerialPort()
{
   _wLacze->SkojarzObiektPortu(&serial);

   serial.setBaudRate(QSerialPort::Baud115200);
   serial.setFlowControl(QSerialPort::NoFlowControl);
   serial.setStopBits(QSerialPort::OneStop);
   serial.setDataBits(QSerialPort::Data8);
   serial.setParity(QSerialPort::NoParity);
   serial.setPortName(QString::fromStdString(_wLacze->_NazwaPortu));

   if (!serial.open(QSerialPort::ReadOnly))
   {
     std::cerr << ":( Blad otwarcia portu " << _wLacze->_NazwaPortu << std::endl;
   }
}
