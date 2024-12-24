#include "mainwindow.h"
#include "./ui_mainwindow.h"


#include <QPushButton>
#include <QProgressBar>
#include <QRadioButton>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->radioButton_1->setText("radio 1");
    ui->radioButton_2->setText("radio 2");

    ui->comboBox->addItem("1 action");
    ui->comboBox->addItem("2 action");
    ui->comboBox->addItem("3 action");
    ui->comboBox->addItem("4 action");

    ui->pushButton->setText("Жми");
    ui->pushButton->setCheckable(true);

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(10);
    ui->progressBar->setValue(0);
    //connect(ui->pushButton, &QPushButton::toggled, this, &MainWindow::on_pushButton_toggled);

}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_toggled(bool checked)
{
    if( ui->progressBar->value()>=10) {
        ui->progressBar->setValue(0);
    }
    else  {
        ui->progressBar->setValue(ui->progressBar->value()+1);
    }
}


