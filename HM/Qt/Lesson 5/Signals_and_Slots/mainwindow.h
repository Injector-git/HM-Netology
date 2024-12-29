#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_start_toggled(bool checked);
    void update_label(const QString &currentTime);

    void on_button_clear_clicked();

    void on_button_loop_clicked();

private:
    Ui::MainWindow *ui;
    Stopwatch *watch; // Указатель на класс таймера
    int loop_number=1; //номер круга
    QTime loop_time_1; //Время круга
    QTime loop_time_2 = QTime(0, 0);
    QTime secondsDifference = QTime(0,0);
};
#endif // MAINWINDOW_H
