#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    digitKeyboard = new DigitKeyboard();
    connect(digitKeyboard, SIGNAL(SendButtonClick(int)),
            this, SLOT(RecvButtonClick(int)));

    ui->centralWidget->setLayout(ui->horizontalLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    digitKeyboard->show();
}

void MainWindow::RecvButtonClick(int i)
{
    QString text;
    text = ui->lineEdit->text();
    switch(i)
    {
    case 9:
        text = text.remove(text.length()-1, 1);
        break;
    case 11:
        qDebug() << "当前输入为：" << text;
        break;
    case 10:
        i = -1;
    default:
        text += QString("%1").arg(i+1);
        break;
    }
    ui->lineEdit->setText(text);
}

void MainWindow::closeEvent(QCloseEvent *)
{
    if(digitKeyboard != NULL)
    {
        digitKeyboard->close();
        delete digitKeyboard;
        digitKeyboard = NULL;
    }
}
