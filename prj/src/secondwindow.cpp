#include "inc/secondwindow.hh"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::makePlot()
{
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
    connect(wSerial, SIGNAL(readyRead()), this, SLOT(realtimeDataSlot()));
}

void SecondWindow::realtimeDataSlot()
{
    static QTime time(QTime::currentTime());
    // calculate two new data points:
    double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds

    for(int i=0;i<4;i++)
    {
        ui->customPlot->graph(i)->addData(key, wData->at(i));
        // rescale value (vertical) axis to fit the current data:
        ui->customPlot->graph(i)->rescaleValueAxis(true);
    }

    // make key axis range scroll with the data (at a constant range size of 8):
    ui->customPlot->xAxis->setRange(key, 8, Qt::AlignRight);
    ui->customPlot->replot();
}
