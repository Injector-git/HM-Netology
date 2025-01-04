#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QTimer>
#include <QTime>
#include <QObject>
#include <QDateTime>

class Stopwatch : public QObject
{
    Q_OBJECT

public:
    Stopwatch(QObject *parent = nullptr): QObject(parent) {

        timer = new QTimer(this); // Создаем новый QTimer
        connect(timer, &QTimer::timeout, this, &Stopwatch::currentTime); // Подключаем сигнал таймера к слоту
    }

    ~Stopwatch();

    void watch_start(); // Запустить таймер

    void watch_stop(); // Остановить таймер

    void clear_time(); //сбросить время

signals:
    void currentTimeUpdated(const QTime &currentTime);

public slots:
    void  currentTime(); // Слот для обработки события таймера

private:
    QTimer *timer;
    QTime timeElapsed = QTime(0, 0, 0);  // Начальное значение времени
};

#endif // STOPWATCH_H
