#ifndef ODBIOR_HH
#define ODBIOR_HH
/*!
  \file
  \brief Szczegóły dotyczące klasy Komunikacja
  */
#include <QSerialPort>
#include <iostream>

class Komunikacja {
public:
     QSerialPort  *_wPort = nullptr;
     bool          _Kontynuuj = true;
     std::string   _NazwaPortu;

   public:
     /*!
      * \brief UstawNazwePortu
      *
      * Metoda odpowiedzialna za ustawienie _NazwaPortu.
      *
      * \param[in] rNazwa Zmienna, z której zostanie wczytana nazwa portu.
      */
     void UstawNazwePortu(const std::string &rNazwa) { _NazwaPortu = rNazwa; }
     /*!
      * \brief SkojarzObiektPortu
      *
      * Metoda odpowiedzialna za ustawienie *_wPort.
      *
      * \param[in] wPort Wskaźnik, na którey zostanie ustawiony *_wPort.
      */
     void SkojarzObiektPortu(QSerialPort  *wPort) { _wPort = wPort; }
     /*!
      * \brief OtworzPort
      *
      * Metoda ustwierająca port szeregowy.
      *
      * \param[in] sPortSzeregowy Zmienna przechowują wskaźnik do tablicy znaków.
      * \retval false - w przypadku błędu otwarcia portu
      * \retval true - w przypadku poprawnego otwarcia portu
      */
     bool OtworzPort(const char* sPortSzeregowy);
     /*!
      * \brief OtworzPort
      *
      * Metoda przesyłająca do metody OtworzPort(const char* sPortSzeregowy) nazwę portu zamienioną na c-stringa.
      *
      * \retval false - w przypadku błędu otwarcia portu
      * \retval true - w przypadku poprawnego otwarcia portu
      */
     bool OtworzPort() { return OtworzPort(_NazwaPortu.c_str()); }
     /*!
      * \brief Kontynuuj
      *
      * Metoda odpowiadająca za sygnalizowanie, czy odczyt ma być kontunuowany.
      *
      * \retval true - kontunuuj odczyt
      * \retval false - zakończ odczyt
      */
     bool Kontynuuj() const { return _Kontynuuj; }
     /*!
      * \brief Zakoncz
      *
      * Metoda odpowiadająca za stgnalizowanie końca odczytu danych.
      */
     void Zakoncz() { _Kontynuuj = false; }
     /*!
      * \brief OdbierzJednaLinie
      *
      * Metoda odczytująca dane z bufora
      *
      * \retval true - istnieją dane oczekujące na odczyt
      * \retval false - nie istnieją dane oczekujące na odczyt
      */
     bool OdbierzJednaLinie();
     /*!
      * \brief OdbiorDanych
      *
      * Metoda wywołująca metodę OdbierzJednaLinie() dopóki pole _Kontynuuj == true
      */
     void OdbiorDanych();
};

#endif // ODBIOR_HH
