#ifndef SECONDWINDOW_HH
#define SECONDWINDOW_HH
/*!
  \file
  \brief Szczegóły dotyczące klasy SecondWindow
  */
#include <QDialog>
#include <QTime>
#include <array>
#include <QDebug>
#include <QCoreApplication>
#include "inc/odbior.hh"

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();
    std::array<int,4> *wData = nullptr;
    QSerialPort *wSerial = nullptr;
    /*!
     * \brief setArray
     *
     * Metoda ustawiająca wskaźnik na std::array<int,4> na odpowiednie pole.
     *
     * \param[in] wArray wskaźnik, za pomocą którego odpowiednie pole jest ustawiane
     */
    void setArray(std::array<int,4> *wArray) { wData = wArray; }
    /*!
     * \brief setSerial
     *
     * Metoda ustawiająca wskaźnik na QSerialPort na odpowiednie pole.
     *
     * \param[in] _wSerial wskaźnik za pomocą którego odpowiednie pole jest ustawiane
     */
    void setSerial(QSerialPort *_wSerial) { wSerial = _wSerial; }
    /*!
     * \brief makePlot
     *
     * Metoda odpowiadająca za wywołanie wykresu.
     */
    void makePlot();

private slots:
    /*!
     * \brief realtimeDataSlot
     *
     * Slot odpowiedzialny za "plotowanie" danych w czasie rzeczywistym.
     */
    void realtimeDataSlot();
private:
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_HH
