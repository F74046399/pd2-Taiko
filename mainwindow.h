#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    int random_number;
    int random;
    int random_number1;

    void keyPressEvent(QKeyEvent*);

    void Score();

    void IncreaseScore();

    void Game();


    ~MainWindow();


private slots:
    void on_ExitButton_clicked();

    void on_StartButton_clicked();

     void on_RestartButton_clicked();

    void move();



    void timer_timeout();


    void on_ExitButton2_clicked();

    void on_StopButton_clicked();

    void on_GoButton_clicked();

    void on_ReturnButton_clicked();

    void on_RButton_clicked();

    void on_CButton_clicked();

    void on_ReadyButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
