#include "digitkeyboard.h"

DigitKeyboard::DigitKeyboard()
{
    resize(500, 310);
    setWindowFlags(Qt::FramelessWindowHint);   //无边框

    m_layout = new QGridLayout;
    m_layout->setSpacing(0);
    m_layout->setContentsMargins(0, 0, 0, 0);

    m_btns = new QButtonGroup;

    int i = 0;
    for(; i < 12; i++)
    {
        DigitButton *digitBtn = new DigitButton;
        if(i < 9)
            digitBtn->setText(QString("%1").arg(i+1));
        m_btns->addButton(digitBtn, i);
        m_layout->addWidget(digitBtn, i/3, i%3);

        if(9 == i)
        {
            digitBtn->setText(QString(""));
            digitBtn->setIconSize(QSize(35, 35));
            digitBtn->setIcon(QIcon(":/icons/revoke.png"));
        }
        if(10 == i)
            digitBtn->setText(QString("0"));
        if(11 == i)
        {
            digitBtn->setText(QString(""));
            digitBtn->setIconSize(QSize(50, 50));
            digitBtn->setIcon(QIcon(":/icons/check.png"));
        }

    }

    connect(m_btns, SIGNAL(buttonClicked(int)),
            this, SIGNAL(SendButtonClick(int)));

    setLayout(m_layout);
    setStyleSheet("QDialog{background-color:white;}");
}

DigitKeyboard::~DigitKeyboard()
{

}

void DigitKeyboard::closeEvent(QCloseEvent *)
{
    int i = 0;
    for(; i < 12; i++)
    {
        QAbstractButton *btn = m_btns->button(i);
        m_btns->removeButton(btn);
        delete btn;
        btn = NULL;
    }
    delete m_btns;
    m_btns = NULL;
    delete m_layout;
    m_layout = NULL;
}

void DigitKeyboard::paintEvent(QPaintEvent *)
{
    if(isVisible())
    {
        m_lines.append(QLine(QPoint(width()/3*1, 0), QPoint(width()/3*1, height())));
        m_lines.append(QLine(QPoint(width()/3*2, 0), QPoint(width()/3*2, height())));
        m_lines.append(QLine(QPoint(0, height()/4*1), QPoint(width(), height()/4*1)));
        m_lines.append(QLine(QPoint(0, height()/4*2), QPoint(width(), height()/4*2)));
        m_lines.append(QLine(QPoint(0, height()/4*3), QPoint(width(), height()/4*3)));

        QPainter painter(this);
        QPen pen(Qt::gray);
        pen.setWidthF(0.3);
        painter.setPen(pen);
        painter.drawLines(m_lines);
        m_lines.clear();
    }
}

