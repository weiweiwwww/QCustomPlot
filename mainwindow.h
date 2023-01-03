#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
    namespace Ui { class MainWindow; }
QT_END_NAMESPACE

    class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onTimeOut();

private:
    void initPlot();
    void updatePlot();

private:
    Ui::MainWindow *ui;
    QTimer *m_timer;
    QVector<double> vectX;
    QVector<double> vectY;
};
#endif // MAINWINDOW_H
