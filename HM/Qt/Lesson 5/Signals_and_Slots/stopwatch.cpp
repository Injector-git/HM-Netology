#include "stopwatch.h"


Stopwatch::Stopwatch(QObject *parent): QObject(parent) {

    timer = new QTimer(this); // Создаем новый QTimer
    connect(timer, &QTimer::timeout, this, &Stopwatch::currentTime); // Подключаем сигнал таймера к слоту
}


Stopwatch::~Stopwatch()
{
    delete timer;
}

void Stopwatch::watch_start() {
    timer->start(1); // Запускаем таймер с заданным интервалом
}

void Stopwatch::watch_stop() {
    timer->stop(); // Останавливаем таймер
}


QTime Stopwatch::watch_loop() {
    secondsDifference = QTime(0, 0);
    loop_time_1=timeElapsed;

    secondsDifference = secondsDifference.addSecs(loop_time_2.secsTo(loop_time_1));

    loop_time_2 = loop_time_1;

    return secondsDifference;
}


void Stopwatch::clear_time(){
    timeElapsed = QTime(0, 0, 0); // Начальное значение времени
}

void Stopwatch::currentTime() {
    timeElapsed = timeElapsed.addMSecs(1);
    emit currentTimeUpdated(timeElapsed);
}
