#include "digitbutton.h"

DigitButton::DigitButton()
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    setStyleSheet("QPushButton:focus{outline: none;}"
                  "QPushButton:pressed{background-color:#bdc3c7;}"
                  "QPushButton{color:black;background-color:transparent;border:none;font-size:35px}");
    setFlat(true);
}
