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
    Stopwatch(QObject *parent = nullptr);

    ~Stopwatch();

    void watch_start(); // Запустить таймер

    void watch_stop(); // Остановить таймер

    QTime watch_loop(); //подсчет круга

    void clear_time(); //сбросить время

signals:
    void currentTimeUpdated(const QTime &currentTime);

public slots:
    void  currentTime(); // Слот для обработки события таймера

private:
    QTimer *timer;
    QTime timeElapsed = QTime(0, 0, 0);  // Начальное значение времени

    QTime loop_time_1 = QTime(0, 0); //Время круга
    QTime loop_time_2 = QTime(0, 0);
    QTime secondsDifference = QTime(0, 0);
};

#endif // STOPWATCH_H
