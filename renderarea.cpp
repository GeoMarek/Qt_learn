#include "renderarea.h"
#include <QPainter>
RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent),
    background_color(0,0,255),
    shape_color(255, 255, 255),
    shape (ShapeType::Astroid)
{

}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(400, 200);
}

void RenderArea::setShape(ShapeType shape)
{
    this->shape = shape;
}

RenderArea::ShapeType RenderArea::getShape() const
{
    return shape;
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);


    switch (shape)
    {
    case ShapeType::Astroid:
        background_color = Qt::red;
        break;
    case ShapeType::Cycloid:
        background_color = Qt::green;
        break;
    case ShapeType::HuygensCyclodid:
        background_color = Qt::blue;
        break;
    case ShapeType::HypoCycloid:
        background_color = Qt::yellow;
        break;
    default:
        break;
    }
    painter.setBrush(QBrush(background_color));
    painter.setPen(shape_color);

    // drawing area
    painter.drawRect(this->rect());
    painter.drawLine(this->rect().topLeft(), this->rect().bottomRight());


}
