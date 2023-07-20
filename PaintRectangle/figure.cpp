#include "figure.h"

Figure::Figure(QObject *parent) : QObject(parent) {
    timer = new QTimer();
    connect( timer, &QTimer::timeout, this, &Figure::timerProcessing );
    timer->start( 500 );
    //callback = nullptr;
    setFlags(QGraphicsItem::ItemIsSelectable|
                        QGraphicsItem::ItemIsMovable);
}

Figure::Figure(void (*function)(QPointF _point, int _figureId ) ): Figure() {
     callback = function;
}

Figure::~Figure(){

}

void Figure::setCallback( void (*function)(QPointF, int) ){
    callback = function;
}


void Figure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen( Qt::black );
    painter->setBrush( color );
    painter->drawRect( boundingRect() );

    Q_UNUSED( option );
    Q_UNUSED( widget );

}

QRectF Figure::boundingRect() const {
    return QRectF( left, top, width, hight );
}

void Figure::mousePressEvent(QGraphicsSceneMouseEvent *event){
    std::cout << "mouse is pressed to figure #" << std::to_string(id) << " " << event->pos().x() << " " << event->pos().y() << std::endl;
    if ( callback != nullptr ) callback( this->pos(), id );
}

//void Figure::mouseMoveEvent(QGraphicsSceneMouseEvent *event){

//}

void Figure::processingKeyboard(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::KeyPress) {
        //std::cout << "key is pressed" << std::endl;
        QKeyEvent*  keyEvent = static_cast<QKeyEvent*>( event );
        if ( keyEvent->key() == Qt::Key_W ) {
            this->setY( y() - 2 );
            color = Qt::red;
        }  else if ( keyEvent->key() == Qt::Key_S ) {
            this->setY( y() + 2 );
            color = Qt::yellow;
        }  else if ( keyEvent->key() == Qt::Key_A ) {
            this->setX( x() - 2 );
            color = Qt::green;
        }  else if ( keyEvent->key() == Qt::Key_D ) {
            this->setX( x() + 2 );
            color = Qt::gray;
        }
    }
}

void Figure::setSize(qreal top, qreal left, qreal width, qreal hight) {
    this->top = top;
    this->left = left;
    this->width = width;
    this->hight = hight;
}


void Figure::timerProcessing(){

    //if ( callback != nullptr ) callback( this->pos(), id );
}
