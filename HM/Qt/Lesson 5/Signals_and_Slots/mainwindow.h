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

private:
    Ui::MainWindow *ui;
    Stopwatch *watch; // Указатель на класс таймера
};
#endif // MAINWINDOW_H
