#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QTimer>
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

    void watch_start(); // Запустить таймер

    void watch_stop(); // Остановить таймер

signals:
    void currentTimeUpdated(const QString &currentTime);

public slots:
    void  currentTime(); // Слот для обработки события таймера

private:
    QTimer *timer;

};

#endif // STOPWATCH_H
