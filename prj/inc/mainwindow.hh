#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH
/*!
  \file
  \brief Szczegóły dotyczące klasy MainWindow
  */
#include <QMainWindow>
#include <QLCDNumber>
#include <QThread>
#include <QBrush>
#include <QtGui>
#include <QtCore>
#include <QGraphicsScene>
#include <QTextStream>
#include "inc/secondwindow.hh"
#include "inc/qcustomplot.hh"
#include <QMenuBar>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
/*!
 * \brief The MainWindow class
 *
 * Klasa odpowiedzialna na zachowanie głównego okna aplikacji.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Komunikacja  *_wLacze = nullptr;
    QSerialPort *serial;
    QTimer *timer;
    std::array<float,6>  data;
    /*!
     * \brief UstawLacze
     *
     * Metoda ustawiająca _wLacze, która pozwala na komunikację aplikacji z pts lub tty.
     *
     * \param[in] wLaczeKom zmienna, w której będzie przechowywany wskaźnik do klasy Komunikacja.
     */
    void UstawLacze(Komunikacja *wLaczeKom) { _wLacze = wLaczeKom; }  

private slots:
    /*!
     * \brief on_pushButton_clicked
     *
     * Slot odpowiedzialny za wywołanie drugiego okna po nacieśnięciu przycisku.
     */
    void on_pushButton_clicked();
    /*!
     * \brief lcdNumber
     *
     * Slot odpowiedzialny za wyświetlanie aktualnej wartości poziomu naładowania baterii.
     */
    void lcdNumber();
    /*!
     * \brief openSerialPort
     *
     * Slot odpowiedzialny za otworzenie portu szeregowego.
     */
    void openSerialPort();
    /*!
     * \brief getData
     *
     * Slot odpowiedzialny za odczytywanie danych z portu szeregowego.
     *
     * \retval true - niepoprawna ramka danych i aplikacja ich nie wczytuje
     * \retval false - poprawna ramka danych i aplikacja je wczytuje
     */
    bool getData();
    /*!
     * \brief progressBar
     *
     * Slot odpowiedzialny za ustawienie wartości na pasku odpowiadającym za wyświetlenie poziomu baterii.
     */
    void progressBar();
    /*!
     * \brief greenLedOn
     *
     * Slot odpowiedzialny za zapalenie się zielonego leda, gdy połączenie zostanie nawiązane.
     */
    void greenLedOn();
    /*!
     * \brief draw
     *
     * Slot odpowiedzialny za ponowne wyrysowanie modelu 2D robota mobilnego.
     */
    void draw();

private:
    int w;
    int h;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem *rect0;
    QGraphicsRectItem *rect1;
    QGraphicsRectItem *rect2;
    QGraphicsRectItem *rect3;
};
#endif // MAINWINDOW_HH
