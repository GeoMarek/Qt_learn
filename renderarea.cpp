#include "renderarea.h"
#include <QPainter>
RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent),
    background_color(Qt::black),
    shape (ShapeType::Astroid),
    pen(Qt::white)
{
    on_shape_changed();
    pen.setWidth(2);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(400, 200);
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

void RenderArea::setScale(float scale)
{
    this->scale = scale;
    repaint();
}

float RenderArea::getScale() const
{
    return scale;
}

void RenderArea::setInterval(float interval)
{
    this->interval_length = interval;
    repaint();
}

void RenderArea::setStepCount(int count)
{
    this->step_count = count;
    repaint();
}

void RenderArea::setShapeColor(QColor color)
{
    pen.setColor(color);
    repaint();
}

float RenderArea::getInterval() const
{
    return interval_length;
}

int RenderArea::getStepCount() const
{
    return step_count;
}

QColor RenderArea::getShapeColor() const
{
    return pen.color();
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QBrush(background_color));
    painter.setPen(pen);
    painter.drawRect(this->rect());

    QPoint center = this->rect().center();
    float step = interval_length / step_count;

    QPointF prev_point = compute(0);
    QPoint prev_pixel;
    prev_pixel.setX(prev_point.x() * scale + center.x());
    prev_pixel.setY(prev_point.y() * scale + center.y());

    for (float t=0; t < interval_length; t += step)
    {
        QPointF point = compute(t);
        QPoint pixel;
        pixel.setX(point.x() * scale + center.x());
        pixel.setY(point.y() * scale + center.y());
        painter.drawLine(pixel, prev_pixel);
        prev_pixel = pixel;
    }

    QPointF point = compute(interval_length);
    QPoint pixel;
    pixel.setX(point.x() * scale + center.x());
    pixel.setY(point.y() * scale + center.y());
    painter.drawLine(pixel, prev_pixel);
    prev_pixel = pixel;

}

void RenderArea::on_shape_changed()
{
    switch (shape)
    {
    case ShapeType::Astroid:
        scale = 90;
        interval_length = static_cast<float>(2 * M_PI);
        step_count = 256;
        break;
    case ShapeType::Cycloid:
        scale = 8;
        interval_length = static_cast<float>(4 * M_PI);
        step_count = 128;
        break;
    case ShapeType::HuygensCyclodid:
        scale = 4;
        interval_length = static_cast<float>(4 * M_PI);
        step_count = 256;
        break;
    case ShapeType::HypoCycloid:
        scale = 15;
        interval_length = static_cast<float>(2 * M_PI);
        step_count = 256;
        break;
    case ShapeType::Line:
        scale = 100;
        interval_length = static_cast<float>(2);
        step_count = 128;
        break;
    case ShapeType::Circle:
        scale = 100;
        interval_length = static_cast<float>(2 * M_PI);
        step_count = 128;
        break;
    case ShapeType::Ellipse:
        scale = 50;
        interval_length = static_cast<float>(2 * M_PI);
        step_count = 256;
        break;
    case ShapeType::Fancy:
        scale = 10;
        interval_length = static_cast<float>(12 * M_PI);
        step_count = 512;
        break;
    case ShapeType::StarFish:
        scale = 25;
        interval_length = static_cast<float>(6 * M_PI);
        step_count = 256;
        break;
    case ShapeType::Cloud:
        scale = 10;
        interval_length = static_cast<float>(28 * M_PI);
        step_count = 128;
        break;
    case ShapeType::InvertedCloud:
        scale = 10;
        interval_length = static_cast<float>(28 * M_PI);
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
    case ShapeType::Circle:
        return compute_circle(t);
        break;
    case ShapeType::Ellipse:
        return compute_ellipes(t);
        break;
    case ShapeType::Fancy:
        return compute_fancy(t);
        break;
    case ShapeType::StarFish:
        return compute_star_fish(t);
        break;
    case ShapeType::Cloud:
        return compute_cloud(t);
        break;
    case ShapeType::InvertedCloud:
        return compute_inverted_cloud(t);
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

QPointF RenderArea::compute_circle(float t)
{
    return QPointF(cos(t), sin(t));
}

QPointF RenderArea::compute_ellipes(float t)
{
    return QPointF(2*cos(t), 1.1*sin(t));
}

QPointF RenderArea::compute_fancy(float t)
{
    auto x = 11.0f * cos(t) - 6 * cos((11.0f/6.0f) * t);
    auto y = 11.0f * sin(t) - 6 * sin((11.0f/6.0f) * t);
    return QPointF(x,y);
}

QPointF RenderArea::compute_star_fish(float t)
{
    auto R = 5;
    auto r = 3;
    auto d = 5;
    auto x = (R-r) * cos(t) + d * cos(t*(R-r/r));
    auto y = (R-r) * sin(t) - d * sin(t*(R-r/r));
    return QPointF(x,y);
}

QPointF RenderArea::compute_cloud(float t)
{
    return compute_cloud_with_sign(t,-1);
}

QPointF RenderArea::compute_inverted_cloud(float t)
{
    return compute_cloud_with_sign(t,1);
}

QPointF RenderArea::compute_cloud_with_sign(float t, float sign)
{
    auto a = 14;
    auto b = 1;
    auto x = (a+b) * cos (t*b/a) + sign * (b * cos (t*(a+b)/a));
    auto y = (a+b) * sin (t*b/a) - b * sin (t*(a+b)/a);
    return QPointF(x,y);
}
