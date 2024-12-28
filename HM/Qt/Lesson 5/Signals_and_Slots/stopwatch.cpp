#include "stopwatch.h"



void Stopwatch::watch_start() {
    timer->start(0.1); // Запускаем таймер с заданным интервалом
}

void Stopwatch::watch_stop() {
    timer->stop(); // Останавливаем таймер
}

void Stopwatch::currentTime() {
    QDateTime current = QDateTime::currentDateTime();
    emit currentTimeUpdated(current.toString("yyyy-MM-dd HH:mm:ss"));
}
