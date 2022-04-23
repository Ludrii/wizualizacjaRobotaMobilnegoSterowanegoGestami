#ifndef SECONDWINDOW_HH
#define SECONDWINDOW_HH

#include <QDialog>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private:
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_HH
