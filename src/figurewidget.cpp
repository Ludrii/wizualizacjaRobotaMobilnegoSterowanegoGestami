#include "inc/figurewidget.hh"
#include <QtGui>

FigureWidget::FigureWidget(QWidget *parent) : QWidget(parent)
{
    QPainter painter(this);
}

void FigureWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    auto size = this->size();
    auto width = this->width();
    auto height = this->height();

    painter.drawRect(width/4,height/4,width/2,height/2);
}
