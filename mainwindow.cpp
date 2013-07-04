#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <oscilloscope/samplingthread.h>
#include <qwtoscmain.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
   /// samplingThread->stop();
   /// samplingThread->wait( 1000 );
   /// delete window;
    delete ui;

}


void MainWindow::on_pushButton_clicked() {

    window = new QwtOSCMain();
    window->setAttribute (Qt::WA_DeleteOnClose);

    window->resize( 800, 400 );
    window->clearData ();

    window->samplingThread = new SamplingThread();

    window->samplingThread->setFrequency( window->frequency() );
    window->samplingThread->setAmplitude( window->amplitude() );
    window->samplingThread->setInterval( window->signalInterval() );

    window->connect( window, SIGNAL( frequencyChanged( double ) ),
            window->samplingThread, SLOT( setFrequency( double ) ) );
    window->connect( window, SIGNAL( amplitudeChanged( double ) ),
            window->samplingThread, SLOT( setAmplitude( double ) ) );
    window->connect( window, SIGNAL( signalIntervalChanged( double ) ),
            window->samplingThread, SLOT( setInterval( double ) ) );


    window->show ();
    window->samplingThread->start();
    window->start();
}
