#include "inc/mainwindow.hh"
#include "ui_mainwindow.h"
#include "inc/secondwindow.hh"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    SecondWindow SecondWindow;
    SecondWindow.setModal(true);
    SecondWindow.exec();
}
