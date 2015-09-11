//
// Created by Francesco Burelli on 11/09/15.
//

#include "Label.h"
#include <QEvent>

Label::Label(int base, QWidget *parent, Qt::WindowFlags f)
        : QLabel(parent, f)
{

    _base = base;

    setAlignment(Qt::AlignRight);
    setStyleSheet("QLabel { background-color : #340000; color : #FF0000; }");
}



void Label::setNumber(Number number) {
    setText(QString::fromStdString(number.baseString(_base)));
}

Number Label::getNumber() {
    return Number(text().toStdString(), _base);
}

void Label::mouseReleaseEvent(QMouseEvent *ev) {
    emit selected();
    QLabel::mouseReleaseEvent(ev);
}

bool Label::event(QEvent *e) {
    bool result = false;
    if (e->type() == QEvent::MouseButtonRelease) {
        //result = true;
    }

    return QLabel::event(e) || result;
}
