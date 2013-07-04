#include <qapplication.h>
#include "mainwindow.h"
#include "samplingthread.h"

int main( int argc, char **argv )
{
    QApplication app( argc, argv );
    app.setPalette( Qt::darkGray );

    MainWindow window;
    window.resize( 800, 400 );

    SamplingThread samplingThread;
    samplingThread.setFrequency( window.frequency() );
    samplingThread.setAmplitude( window.amplitude() );
    samplingThread.setInterval( window.signalInterval() );

    //主窗体value changed信号触发了frequencyChanged, ampchanged, intervalchanged
    window.connect( &window, SIGNAL( frequencyChanged( double ) ),
        &samplingThread, SLOT( setFrequency( double ) ) );
    window.connect( &window, SIGNAL( amplitudeChanged( double ) ),
        &samplingThread, SLOT( setAmplitude( double ) ) );
    //设置QwtThread中sample的间隔
    window.connect( &window, SIGNAL( signalIntervalChanged( double ) ),
        &samplingThread, SLOT( setInterval( double ) ) );

    window.show();

    samplingThread.start();
    window.start();

    bool ok = app.exec();

    samplingThread.stop();
    samplingThread.wait( 1000 );

    return ok;
}
