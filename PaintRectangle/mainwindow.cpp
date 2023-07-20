#include "mainwindow.h"
#include "./ui_mainwindow.h"

QLineEdit* MainWindow::x;
QLineEdit* MainWindow::y;
QLineEdit* MainWindow::figureInformation;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    scene = new QGraphicsScene(0, 0, 800, 300, this);
    ui->graphicsView->setScene( scene );
    //ui->graphicsView->scale( -2, 4 );

    x = new QLineEdit();
    y = new QLineEdit();
    figureInformation = new QLineEdit();

    ui->gridLayout->addWidget( x, 0, 1 );
    ui->gridLayout->addWidget( y, 1, 1 );
    ui->gridLayout->addWidget( figureInformation, 2, 1 );

//    auto figure = new Figure( getPosition );
//    figure->setSize( 0, 0, 20, 20 );
//    figure->setId( 1 );
//    scene->addItem( figure );
//    figures.append( figure );

    for( int _i = 0 ; _i < 40 ; _i++ ){
        Figure*         _f = new Figure( getPosition );
                        _f->setId( _i + 1 );
                        figures.append( _f );

        if ( _i > 0 )   _f->setSize( figures.at( _i - 1 )->getTop(), figures.at( _i - 1 )->getLeft() + _f->getWidth() + 5, _f->getWidth(), _f->getHight() );
        else            _f->setSize( figures.at( _i )->getTop(), figures.at( _i )->getLeft() + _f->getWidth() + 5, _f->getWidth(), _f->getHight() );
        scene->addItem( _f );
    }

    installEventFilter( this );
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    //ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);


}

MainWindow::~MainWindow() {
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
    for( const auto& _f: figures ){
        _f->processingKeyboard( obj, event );
    }

    return false;
}

//void MainWindow::mousePressEvent(QMouseEvent*   event) {
//    //setCursor( QCursor(Qt::ClosedHandCursor) );
//    std::cout << "event position : x = " << event->pos().x() << " y = " << event->pos().y() << std::endl;
//    auto _coord = ui->graphicsView->mapToScene( event->pos() );
//    std::cout << "coord : x = " << _coord.x() << " y = " << _coord.y() << std::endl;

//}

//void MainWindow::mouseReleaseEvent(QMouseEvent* event){
//   this->setCursor(QCursor(Qt::ArrowCursor));
//}

void MainWindow::getPosition(QPointF _point, int _figureId){

    x->setText( QString::number( _point.x() )  );
    y->setText( QString::number( _point.y() )  );
    figureInformation->setText( QString::number( _figureId ) );
}



