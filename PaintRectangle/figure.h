#ifndef FIGURE_H
#define FIGURE_H

#include <QWidget>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>

#include <iostream>

class Figure : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit    Figure(QObject *parent = nullptr);
                Figure( void (*function)(QPointF _point, int _figureId) );
    virtual     ~Figure();
    void        setCallback( void (*function)(QPointF _point, int _figureId) );
    void        processingKeyboard(QObject* obj, QEvent* event);
    void        setSize( qreal top, qreal left, qreal width, qreal hight );

    qreal       getTop() const { return top; }
    qreal       getLeft() const { return left; }
    qreal       getWidth() const { return width; }
    qreal       getHight() const { return hight; }

    int         getId() const { return id; }
    void        setId(int value) { id = value; }

private:
    void (*callback)(QPointF _point, int _figureId) = { nullptr };
    QTimer*     timer { nullptr };
    qreal       top { 0 }, left { 0 }, width { 20 }, hight { 20 };
    int         id = 0;
    QColor      color { Qt::green };

protected:
    void    paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF  boundingRect() const override;
     void   mousePressEvent(QGraphicsSceneMouseEvent *event) override;
     //void   mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;


private slots:
    void timerProcessing();

};

#endif // FIGURE_H
