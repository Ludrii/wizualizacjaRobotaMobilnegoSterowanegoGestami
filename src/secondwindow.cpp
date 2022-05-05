#include "inc/secondwindow.hh"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    SecondWindow::makePlot();
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::makePlot()
{
    ui->customPlot->addGraph();
    ui->customPlot->addGraph();
    ui->customPlot->addGraph();
    ui->customPlot->addGraph();

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
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
    std::cout<<"Czy ja tu wgle wchodze?"<<std::endl;
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
        std::cout<<data.at(i)<<endl;
    }

    // make key axis range scroll with the data (at a constant range size of 8):
    ui->customPlot->xAxis->setRange(key, 8, Qt::AlignRight);
    ui->customPlot->replot();
}
