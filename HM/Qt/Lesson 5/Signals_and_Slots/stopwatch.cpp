#include "stopwatch.h"



Stopwatch::~Stopwatch()
{
    delete timer;
}

void Stopwatch::watch_start() {
    timer->start(0.1); // Запускаем таймер с заданным интервалом
}

void Stopwatch::watch_stop() {
    timer->stop(); // Останавливаем таймер
}

void Stopwatch::clear_time(){
    timeElapsed = QTime(0, 0); // Начальное значение времени
}

void Stopwatch::currentTime() {
    timeElapsed = timeElapsed.addMSecs(1);
    emit currentTimeUpdated(timeElapsed);
}
