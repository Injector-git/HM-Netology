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

    ui->label->setText("00:00:00");
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

        watch->currentTime();

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
    ui->label->setText("00:00:00");
    watch->clear_time();

    loop_number=1;
    ui->textBrowser->clear();
    loop_time_1=QTime(0,0);
    loop_time_2=QTime(0,0);
    secondsDifference = QTime(0,0);
}


void MainWindow::on_button_loop_clicked()
{
    loop_time_1=QTime::fromString(ui->label->text(), "hh:mm:ss");
    secondsDifference = secondsDifference.addSecs(loop_time_2.secsTo(loop_time_1));

    ui->textBrowser->append(QString::number(loop_number)+ " " + secondsDifference.toString("hh:mm:ss") + " (" + loop_time_1.toString("hh:mm:ss") + " " + loop_time_2.toString("hh:mm:ss") + ")");

    secondsDifference = QTime(0,0);
    loop_time_2 = loop_time_1;
    loop_number++;
}

