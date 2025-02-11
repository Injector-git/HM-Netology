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

    //textBrowser

    ui->textBrowser->setReadOnly(true);

        //textBrowser


    //таймер

    ui->label->setText("00:00:00.000");
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


void MainWindow::update_label(const QTime &currentTime) {
    ui->label->setText(currentTime.toString("hh:mm:ss.zzz")); // Обновляем текст QLabel
}

void MainWindow::on_button_start_toggled(bool checked)
{
    if(checked){
        ui->button_start->setText("Stop");
        ui->button_loop->setEnabled(true);

        watch->watch_start();


    }
    else {
        ui->button_start->setText("Start");
        ui->button_loop->setEnabled(false);

        watch->watch_stop();
    }
}


void MainWindow::on_button_clear_clicked()
{
    //обнулить показатели
    ui->label->setText("00:00:00.000");
    watch->clear_time();

    loop_number=1;
    ui->textBrowser->clear();

}


void MainWindow::on_button_loop_clicked()
{

    ui->textBrowser->append("loop: " + QString::number(loop_number)+ " time: " + watch->watch_loop().toString("hh:mm:ss")  );

    loop_number++;
}
