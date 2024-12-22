#include "mainwindow.h"
#include "./ui_mainwindow.h"


#include <QPushButton>
#include <QProgressBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::toggled, this, &MainWindow::on_pushButton_toggled);

}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_toggled(bool checked)
{
    if( ui->progressBar->value()>100)  ui->progressBar->setValue(0);
    else  ui->progressBar->setValue(ui->progressBar->value()+10);
}


