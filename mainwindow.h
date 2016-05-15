#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void time_timeout();

    void moving_red();

    void moving_red2();

    void moving_blue();

    void moving_blue2();

    void on_start_clicked();

    void on_exit_clicked();

    void keyPressEvent(QKeyEvent *event);

    void generating();

    void on_restart_clicked();

private:
    Ui::MainWindow *ui;
    int count=30;
    int score=0;
    int r;
};

#endif // MAINWINDOW_H
