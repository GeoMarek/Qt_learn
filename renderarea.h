#ifndef RENDERAREA_H
#define RENDERAREA_H
#define _USE_MATH_DEFINES
#include <QWidget>
#include <QColor>
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
        HypoCycloid
    };
    void setBackgroundColor(QColor color) { background_color = color; }
    QColor getBackgroundColor() const { return background_color; }
    void setShape(ShapeType shape);
    ShapeType getShape() const;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    void on_shape_changed();
    QPointF compute(float t);
    QPointF compute_astroid(float t);
    QPointF compute_cycloid(float t);
    QPointF compute_huygens_cycloid(float t);
    QPointF compute_hypo_cycloid(float t);

private:
    QColor background_color;
    QColor shape_color;
    ShapeType shape;

    float interval_length;
    float scale;
    int step_count;

signals:

};

#endif // RENDERAREA_H
