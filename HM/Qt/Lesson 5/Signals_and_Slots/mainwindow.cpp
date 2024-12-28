#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //кнопки

    ui->button_start->setText("Start");
    ui->button_start->setCheckable(true);

    ui->button_clear->setText("Clear");

    ui->button_loop->setText("Круг");
    ui->button_loop->setEnabled(false);

        //кнопки

    //таймер

    // Создаем экземпляр Stopwatch
    watch = new Stopwatch(this);
    // Подключаем сигнал к слоту
    connect(watch, &Stopwatch::currentTimeUpdated, this, &MainWindow::update_label);

        //таймер


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::update_label(const QString &currentTime) {
    ui->label->setText(currentTime); // Обновляем текст QLabel
}

void MainWindow::on_button_start_toggled(bool checked)
{
    if(checked){
        ui->button_start->setText("Stop");
        ui->button_loop->setEnabled(true);

        watch->watch_start();

        update_label(????);

    }
    else {
        ui->button_start->setText("Start");
        ui->button_loop->setEnabled(false);

        watch->watch_stop();
    }
}

