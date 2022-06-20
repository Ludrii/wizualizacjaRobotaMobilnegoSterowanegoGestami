#include "inc/mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort;
    timer = new QTimer;
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->fitInView(0, 0, scene->width(), scene->height());
    w = ui->graphicsView->width();
    h = ui->graphicsView->height();
    rect0 = scene->addRect(w/2,h/2,w/2,h/2);
    rect1 = scene->addRect(w,h/2,w/2,h/2);
    rect2 = scene->addRect(w/2,h,w/2,h/2);
    rect3 = scene->addRect(w,h,w/2,h/2);
    QTimer::singleShot(1000,this, SLOT(openSerialPort()));
    connect(serial, SIGNAL(readyRead()), this, SLOT(getData()));
    connect(serial, SIGNAL(readyRead()), this, SLOT(lcdNumber()));
    connect(serial, SIGNAL(readyRead()), this, SLOT(progressBar()));
    connect(serial, SIGNAL(readyRead()), this, SLOT(draw()));
}

MainWindow::~MainWindow()
{
    delete ui;
    serial->close();
}


void MainWindow::on_pushButton_clicked()
{
    SecondWindow sW(this);
    sW.setArray(&data);
    sW.setSerial(serial);
    sW.makePlot();
    sW.show();
    sW.exec();
}

void MainWindow::lcdNumber()
{
    ui->lcdNumber->display(data.at(4));
}

void MainWindow::openSerialPort()
{
    _wLacze->SkojarzObiektPortu(serial);

    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setPortName(QString::fromStdString(_wLacze->_NazwaPortu));

    if(!serial->open(QSerialPort::ReadOnly))
    {
        std::cerr <<":( Blad otwarcia portu "<< _wLacze->_NazwaPortu << std::endl;
    }
    else
    {
        greenLedOn();
    }
}

bool MainWindow::getData()
{
    QTextStream stream(serial->readAll());
    QString msgBegin, msgEnd;
    std::array<float,7> temp;
    int sumComputed;

    stream>>msgBegin;

    if(msgBegin!="X")
        return 1;

    for(int i=0;i<7;i++)
    {
        stream>>temp.at(i);
    }

    stream>>msgEnd;
    if(msgEnd!="FC")
        return 1;
    sumComputed=temp.at(0)+2*temp.at(1)+3*temp.at(2)+4*temp.at(3)+5*temp.at(4)+6*temp.at(5);
    if(sumComputed==temp.at(6))
    {
        for(int i=0;i<6;i++)
        {
            data.at(i)=temp.at(i);
        }
    }
    return 0;
}

void MainWindow::progressBar()
{
    ui->progressBar->setValue(data.at(5));
}

void MainWindow::greenLedOn()
{
    ui->led->setPixmap(QPixmap(":/img/led_green.png"));
}

void MainWindow::draw()
{
    if(data.at(0)<=2)
    {
        rect0->setBrush(Qt::red);
    }
    else if(data.at(0)<=4)
    {
        rect0->setBrush(Qt::yellow);
    }
    else
    {
        rect0->setBrush(Qt::green);
    }
    rect0->update();
    if(data.at(1)<=2)
    {
        rect1->setBrush(Qt::red);
    }
    else if(data.at(1)<=4)
    {
        rect1->setBrush(Qt::yellow);
    }
    else
    {
        rect1->setBrush(Qt::green);
    }
    rect1->update();
    if(data.at(2)<=2)
    {
        rect2->setBrush(Qt::red);
    }
    else if(data.at(2)<=4)
    {
        rect2->setBrush(Qt::yellow);
    }
    else
    {
        rect2->setBrush(Qt::green);
    }
    rect2->update();
    if(data.at(3)<=2)
    {
        rect3->setBrush(Qt::red);
    }
    else if(data.at(3)<=4)
    {
        rect3->setBrush(Qt::yellow);
    }
    else
    {
        rect3->setBrush(Qt::green);
    }
    rect3->update();
    ui->graphicsView->fitInView( scene->sceneRect(), Qt::KeepAspectRatio );
}
