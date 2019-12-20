#ifndef DIGITKEYBOARD_H
#define DIGITKEYBOARD_H

#include <QDialog>
#include <QLayout>
#include <QButtonGroup>
#include <QCloseEvent>
#include <QPainter>
#include <QDebug>

#include "digitbutton.h"

class DigitKeyboard : public QDialog
{
    Q_OBJECT

public:
    DigitKeyboard();
    ~DigitKeyboard();

private:
    QGridLayout *m_layout;
    QButtonGroup *m_btns;
    QVector<QLine> m_lines;

protected:
    void closeEvent(QCloseEvent *);
    void paintEvent(QPaintEvent *);

signals:
    void SendButtonClick(int i);

};

#endif // DIGITKEYBOARD_H
