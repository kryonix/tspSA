#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->widget->tsp = &tsp;

    tsp.init(10);

    timer.setInterval(100);

    connect(&timer, SIGNAL(timeout()), ui->widget, SLOT(repaint()));

    calc.setInterval(10);

    connect(&calc, SIGNAL(timeout()), this, SLOT(calcNew()));

    timer.start();
    calc.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    tsp.init(ui->spinBox->value());
}

void MainWindow::calcNew()
{
    for(int i = 0; i < 512*5; i++)
    tsp.step();

//    qDebug() << "Heat: " << tsp.heat;
}
