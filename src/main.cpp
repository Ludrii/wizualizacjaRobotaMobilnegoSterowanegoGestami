#include "inc/mainwindow.hh"
#include <fcntl.h>
#include <iostream>
#include <QApplication>
#include "inc/odbior.hh"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Komunikacja LaczeKom;

    if(argc<2)
    {
        std::cout<<"Error"<<std::endl;
        return 1;
    }

    LaczeKom.UstawNazwePortu(argv[1]);

    //LaczeKom.UstawNazwePortu("/dev/pts/4"); // potrzebne przy debugowaniu
    w.UstawLacze(&LaczeKom);
    w.show();

    return a.exec();
}
