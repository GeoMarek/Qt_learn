#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>

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
    QColor background_color;
    QColor shape_color;
    ShapeType shape;


signals:

};

#endif // RENDERAREA_H
