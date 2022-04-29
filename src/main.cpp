#include "inc/mainwindow.hh"
#include <fcntl.h>
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    int fd=open("/dev/ptmx",O_RDWR|O_NOCTTY);
    if(fd==-1)
    {
        std::cerr<<"Error opening file"<<std::endl;
        return -1;
    }

    grantpt(fd);
    unlockpt(fd);

    char* pts_name=ptsname(fd);
    std::cout<<"ptsname: "<<pts_name<<std::endl;

    return a.exec();
}
