#include "../inc/figurewidget.hh"
#include <QtGui>

FigureWidget::FigureWidget(QWidget *parent) : QWidget(parent)
{

}

void FigureWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    auto size = this->size();
    auto offset = 4;

    painter.drawEllipse(0,0,size.width()-offset,size.height()-offset);
}
