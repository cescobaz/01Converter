//
// Created by Francesco Burelli on 15/09/15.
//

#include "CharLabel.h"

CharLabel::CharLabel(QWidget *parent, Qt::WindowFlags f)
        : Label(0, parent, f) {



}

void CharLabel::setNumber(Number number) {
    setText(QString(QChar(number.uint16())));
}

Number CharLabel::getNumber() {
    return Number(0);
}
