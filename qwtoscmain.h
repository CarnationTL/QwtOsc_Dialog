#ifndef QWTOSCMAIN_H
#define QWTOSCMAIN_H

#include <QWidget>
#include "oscilloscope/samplingthread.h"
class Plot;
class Knob;
class WheelBox;


class QwtOSCMain : public QWidget
{
    Q_OBJECT
public:
    explicit QwtOSCMain(QWidget *parent = 0);
    ~QwtOSCMain();
    void start();

    SamplingThread *samplingThread;
    double amplitude() const;
    double frequency() const;
    double signalInterval() const;
signals:
    
public Q_SLOTS:
    bool close ();
    void clearData();
Q_SIGNALS:
    void amplitudeChanged( double );
    void frequencyChanged( double );
    void signalIntervalChanged( double );

private:
    Knob *d_frequencyKnob;
    Knob *d_amplitudeKnob;
    WheelBox *d_timerWheel;
    WheelBox *d_intervalWheel;

    Plot *d_plot;
};

#endif // QWTOSCMAIN_H
