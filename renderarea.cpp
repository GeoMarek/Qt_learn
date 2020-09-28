#include "renderarea.h"
#include <QPainter>
RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent),
    background_color(0,0,255),
    shape_color(255, 255, 255),
    shape (ShapeType::Astroid)
{
    on_shape_changed();
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
    on_shape_changed();
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

    painter.setBrush(QBrush(background_color));
    painter.setPen(shape_color);
    painter.drawRect(this->rect());

    auto center = this->rect().center();
    float step = interval_length / step_count;
    for (float t=0; t < interval_length; t += step)
    {
        QPointF point = compute(t);
        QPoint pixel;
        pixel.setX(point.x() * scale + center.x());
        pixel.setY(point.y() * scale + center.y());
        painter.drawPoint(pixel);
    }


}

void RenderArea::on_shape_changed()
{
    switch (shape)
    {
    case ShapeType::Astroid:
        scale = 40;
        interval_length = 2 * M_PI;
        step_count = 256;
        break;
    case ShapeType::Cycloid:
        scale = 4;
        interval_length = 6 * M_PI;
        step_count = 128;
        break;
    case ShapeType::HuygensCyclodid:
        scale = 4;
        interval_length = 4 * M_PI;
        step_count = 256;
        break;
    case ShapeType::HypoCycloid:
        scale = 15;
        interval_length = 2 * M_PI;
        step_count = 256;
        break;
    case ShapeType::Line:
        scale = 100;
        interval_length = 1;
        step_count = 128;
        break;
    default:
        break;
    }
}

QPointF RenderArea::compute(float t)
{
    switch (shape)
    {
    case ShapeType::Astroid:
        return compute_astroid(t);
        break;
    case ShapeType::Cycloid:
        return compute_cycloid(t);
        break;
    case ShapeType::HuygensCyclodid:
        return compute_huygens_cycloid(t);
        break;
    case ShapeType::HypoCycloid:
        return compute_hypo_cycloid(t);
        break;
    case ShapeType::Line:
        return compute_line(t);
        break;
    default:
        break;
    }
    return QPointF();
}

QPointF RenderArea::compute_astroid(float t)
{
    auto x = pow(cos(t), 3);
    auto y = pow(sin(t), 3);
    return QPointF(x, y);
}

QPointF RenderArea::compute_cycloid(float t)
{
    auto x = 1.5 * (1 - cos(t));
    auto y = 1.5 * (t - sin(t));
    return QPointF(x, y);
}

QPointF RenderArea::compute_huygens_cycloid(float t)
{
    auto x = 4 * (3*cos(t) - cos(3*t));
    auto y = 4 * (3*sin(t) - sin(3*t));
    return QPointF(x, y);
}

QPointF RenderArea::compute_hypo_cycloid(float t)
{
    float x = 1.5 * (2 * cos(t) + cos(2*t));
    float y = 1.5 * (2 * sin(t) - sin(2*t));
    return QPointF(x, y);
}

QPointF RenderArea::compute_line(float t)
{
    return QPointF(1-t, 1-t);
}
