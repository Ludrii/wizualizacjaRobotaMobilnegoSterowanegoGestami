#ifndef FIGUREWIDGET_HH
#define FIGUREWIDGET_HH

#include <QObject>
#include <QWidget>

class QPaintEvent;

class FigureWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FigureWidget(QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent *event);

signals:

};

#endif // FIGUREWIDGET_HH
