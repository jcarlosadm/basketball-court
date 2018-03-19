#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->openGLWidget->context();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    OGLWidget::setLineSize(1.0f + (position * 0.2f));
}

void MainWindow::on_verticalSlider_sliderMoved(int position)
{
    OGLWidget::setLineColorRed(position/100.0f);
}

void MainWindow::on_verticalSlider_2_sliderMoved(int position)
{
    OGLWidget::setLineColorGreen(position/100.0f);
}

void MainWindow::on_verticalSlider_3_sliderMoved(int position)
{
    OGLWidget::setLineColorBlue(position/100.0f);
}
