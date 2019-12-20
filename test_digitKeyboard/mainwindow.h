#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "digitkeyboard.h"

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
    void on_pushButton_clicked();

    void RecvButtonClick(int i);

protected:
    void closeEvent(QCloseEvent *);

private:
    Ui::MainWindow *ui;

    DigitKeyboard *digitKeyboard;
};

#endif // MAINWINDOW_H
