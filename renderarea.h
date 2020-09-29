#ifndef RENDERAREA_H
#define RENDERAREA_H
#define _USE_MATH_DEFINES
#include <QWidget>
#include <QColor>
#include <QPen>
#include "math.h"

class RenderArea : public QWidget
{
public:
    explicit RenderArea(QWidget *parent = nullptr);
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    enum class ShapeType{
        Astroid,
        Cycloid,
        HuygensCyclodid,
        HypoCycloid,
        Line,
        Circle,
        Ellipse,
        Fancy,
        StarFish,
        Cloud,
        InvertedCloud
    };


    void setBackgroundColor(QColor color) { background_color = color; }
    void setShape(ShapeType shape);
    void setScale(float scale);
    void setInterval(float interval);
    void setStepCount(int count);
    void setShapeColor(QColor color);

    QColor getBackgroundColor() const { return background_color; }
    ShapeType getShape() const;
    float getScale() const;
    float getInterval() const;
    int getStepCount() const;
    QColor getShapeColor() const;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    void on_shape_changed();
    QPointF compute(float t);
    QPointF compute_astroid(float t);
    QPointF compute_cycloid(float t);
    QPointF compute_huygens_cycloid(float t);
    QPointF compute_hypo_cycloid(float t);
    QPointF compute_line(float t);
    QPointF compute_circle(float t);
    QPointF compute_ellipes(float t);
    QPointF compute_fancy(float t);
    QPointF compute_star_fish(float t);
    QPointF compute_cloud(float t);
    QPointF compute_inverted_cloud(float t);
    QPointF compute_cloud_with_sign(float t, float sign);



private:
    QColor background_color;
    ShapeType shape;
    QPen pen;

    float interval_length;
    float scale;
    int step_count;

signals:

};

#endif // RENDERAREA_H
