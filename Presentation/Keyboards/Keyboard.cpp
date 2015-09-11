//
// Created by Francesco Burelli on 11/09/15.
//

#include "Keyboard.h"

#include <QPushButton>
#include <QtMath>

Keyboard::Keyboard(const QVector<QString> &values, int columns, QWidget *parent)
        : QWidget(parent)
{
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setSpacing(0);
    gridLayout->setMargin(0);
    gridLayout->setContentsMargins(0,0,0,0);
    this->setLayout(gridLayout);

    int rows = qCeil(qreal(values.size()) / qreal(columns));
    int column = 0, row = 0;
    for (const QString & value : values)
    {
        QPushButton *button = new QPushButton(value);
        button->setObjectName(value);
        if (value == "") {
            button->setEnabled(false);
        }
        connect(button, SIGNAL(pressed()), this, SLOT(pressedButton()));
        gridLayout->addWidget(button,row,column);

        column = (column + 1) % columns;
        if (column == 0) {
            row = (row + 1) % rows;
        }
    }
}

Keyboard::Keyboard(int base, int columns, QWidget *parent)
{
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setSpacing(0);
    gridLayout->setMargin(0);
    gridLayout->setContentsMargins(0,0,0,0);
    this->setLayout(gridLayout);

    int elementsCount = base + 1;
    while (elementsCount % columns != 0)
        elementsCount++;
    int rows = qCeil(qreal(elementsCount) / qreal(columns));
    int column = 0, row = 0;
    for (int v = 0; v < elementsCount; ++v) {
        char c;
        if (v < 9) {
            c = '0' + v + 1;
        }
        else {
            c = 'A' + v - 10 + 1;
        }


        QString value;
        if (v + 1 >= base) {
            if (column + 1 == columns) {
                value = QString("delete");
            }
            else if (((column + 1) / 2) == columns / 2) {
                value = "0";
            }
            else {
                value = "";
            }
        }
        else {
            value = QString(c);
        }

        QPushButton *button = new QPushButton(value);
        button->setObjectName(value);
        if (value == "") {
            button->setEnabled(false);
        }
        connect(button, SIGNAL(pressed()), this, SLOT(pressedButton()));
        gridLayout->addWidget(button,row,column);

        column = (column + 1) % columns;
        if (column == 0) {
            row = (row + 1);
        }
    }

}

void Keyboard::pressedButton() {
    QString senderObjectName = sender()->objectName();

    if (senderObjectName == "delete") {
        senderObjectName = "";
    }
    else if (senderObjectName == "") {
        return;
    }

    emit pressedButton(senderObjectName);
}
