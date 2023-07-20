#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QLineEdit>


#include "figure.h"
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
         bool   eventFilter(QObject* obj, QEvent* event) override;
//         void   mousePressEvent(QMouseEvent*    event) override;
//         void   mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::MainWindow*    ui;
    QGraphicsScene*    scene { nullptr };
    static QLineEdit*  x;
    static QLineEdit*  y;
    static QLineEdit*  figureInformation;
    QVector<Figure*>   figures;

    static void        getPosition(QPointF _point, int _figureId);
};
#endif // MAINWINDOW_H
