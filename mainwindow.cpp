#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initPlot();

    m_timer=new QTimer(this);
    connect(m_timer,SIGNAL(timeout()),this,SLOT(onTimeOut()));
    m_timer->start(500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initPlot()
{
    //随机生成10个数
    for (int i = 0; i < 20;i++) {
        int val=QRandomGenerator::global()->bounded(10);
        vectX.append(i);
        vectY.append(val);
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(vectX, vectY);           // 为曲线图添加数据
    ui->customPlot->graph(0)->setName(tr("第一个示例"));        // 设置曲线图的名字
    ui->customPlot->xAxis->setLabel("x");                      // 设置x轴的标签
    ui->customPlot->yAxis->setLabel("y");
    ui->customPlot->xAxis->setRange(0, 20);                    // 设置x轴的范围为(0,20)
    ui->customPlot->yAxis->setRange(0, 10);
    ui->customPlot->legend->setVisible(true);                  // 显示图例
    //设置基本坐标轴（左侧Y轴和下方X轴）可拖动、可缩放、曲线可选、legend可选、设置伸缩比例，使所有图例可见
    ui->customPlot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom| QCP::iSelectAxes |
                                QCP::iSelectLegend | QCP::iSelectPlottables);
}

//移除首个点，并追加一个点，重新绘制图表
void MainWindow::updatePlot()
{
    int val=QRandomGenerator::global()->bounded(10);
    vectY.removeAt(0);
    vectY.append(val);
    ui->customPlot->graph(0)->setData(vectX, vectY);
    ui->customPlot->replot();
}

void MainWindow::onTimeOut(){
    updatePlot();
}
