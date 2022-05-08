#include "inc/odbior.hh"

using namespace std;

bool Komunikacja::OtworzPort(const char* sPortSzeregowy)
{
  _wPort = new QSerialPort();
  _wPort->setBaudRate(QSerialPort::Baud115200);
  _wPort->setFlowControl(QSerialPort::NoFlowControl);
  _wPort->setStopBits(QSerialPort::OneStop);
  _wPort->setDataBits(QSerialPort::Data8);
  _wPort->setParity(QSerialPort::NoParity);
  _wPort->setPortName(sPortSzeregowy);

  if (!_wPort->open(QSerialPort::ReadOnly)) {
    cerr << ":( Blad otwarcia portu " << sPortSzeregowy << endl;
    return false;
  }
  return true;
}

bool Komunikacja::OdbierzJednaLinie()
{
#define  ROZ_LINII 200
  char Linia[ROZ_LINII+1];
  qint64  IloscOdebranych;

  IloscOdebranych  = _wPort->readLine(Linia, ROZ_LINII); // Czeka az bedzie pelna linia.

  if (IloscOdebranych == 0 && !_wPort->waitForReadyRead()) return false;

  if (IloscOdebranych > 0) {
    if (Linia[strlen(Linia)-1] == '\n') {
       Linia[strlen(Linia)-1] = 0;
    }
  }
  return true;
}

void Komunikacja::OdbiorDanych()
{
  while (Kontynuuj()) {
    if (!OdbierzJednaLinie()) return;
  }
}
