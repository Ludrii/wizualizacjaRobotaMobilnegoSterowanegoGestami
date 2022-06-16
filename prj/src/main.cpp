/*!
  \file
  \brief Szczegóły o main.cpp.

  Plik zawiera funkcję main(), która startuje aplikację.
*/
#include "inc/mainwindow.hh"
#include <fcntl.h>
#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Komunikacja LaczeKom;
    QTranslator translator;
    QStringList languages;

    languages<<"Polski"<<"English";


    if(argc<2)
    {
        std::cout<<"Error"<<std::endl;
        return 1;
    }

    LaczeKom.UstawNazwePortu(argv[1]);

    //LaczeKom.UstawNazwePortu("/dev/pts/4"); // potrzebne przy debugowaniu

    QString lang = QInputDialog::getItem(NULL, "Wybierz język", "Język", languages);

    if(lang=="English")
    {
        translator.load(":/lang/wizualizacjaRobotaMobilnegoSterowanegoGestami_en_150.qm");
        a.installTranslator(&translator);
    }

    MainWindow w;
    w.UstawLacze(&LaczeKom);
    w.show();

    return a.exec();
}
