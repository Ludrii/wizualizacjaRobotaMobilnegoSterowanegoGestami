#ifndef ODBIOR_HH
#define ODBIOR_HH

#include <QSerialPort>
#include <iostream>

class Komunikacja {
public:
     QSerialPort  *_wPort = nullptr;
     bool          _Kontynuuj = true;
     std::string   _NazwaPortu;

   public:

     void UstawNazwePortu(const std::string &rNazwa) { _NazwaPortu = rNazwa; }
     void SkojarzObiektPortu(QSerialPort  *wPort) { _wPort = wPort; }

     bool OtworzPort(const char* sPortSzeregowy);
     bool OtworzPort() { return OtworzPort(_NazwaPortu.c_str()); }

     bool Kontynuuj() const { return _Kontynuuj; }
     void Zakoncz() { _Kontynuuj = false; }

     bool OdbierzJednaLinie();
     void OdbiorDanych();
};

#endif // ODBIOR_HH
