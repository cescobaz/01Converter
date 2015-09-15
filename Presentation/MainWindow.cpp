//
// Created by Francesco Burelli on 11/09/15.
//

#include "MainWindow.h"

#include "Labels/CharLabel.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
{
    _currentKeyboard = 0;

    _mainLayout = new QVBoxLayout;
    _mainLayout->setSpacing(0);
    _mainLayout->setMargin(0);
    _mainLayout->setContentsMargins(10,10,10,0);

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(_mainLayout);
    this->setCentralWidget(centralWidget);

    // create labels
    Label * label = new Label(2);
    label->setObjectName("2");
    _labels[label->objectName()] = label;
    connect(label, SIGNAL(selected()), this, SLOT(labelSelected()));
    _mainLayout->addWidget(label);

    // second row: UInt16 Hex
    QWidget *row = new QWidget;
    QLayout *rowLayout = new QHBoxLayout;
    rowLayout->setSpacing(0);
    rowLayout->setMargin(0);
    row->setLayout(rowLayout);
    _mainLayout->addWidget(row);

    label = new Label(10);
    label->setObjectName("10");
    _labels[label->objectName()] = label;
    connect(label, SIGNAL(selected()), this, SLOT(labelSelected()));
    row->layout()->addWidget(label);

    label = new Label(16);
    label->setObjectName("16");
    _labels[label->objectName()] = label;
    connect(label, SIGNAL(selected()), this, SLOT(labelSelected()));
    row->layout()->addWidget(label);

    // third row: Octal Char
    row = new QWidget;
    rowLayout = new QHBoxLayout;
    rowLayout->setSpacing(0);
    rowLayout->setMargin(0);
    row->setLayout(rowLayout);
    _mainLayout->addWidget(row);

    label = new Label(8);
    label->setObjectName("8");
    _labels[label->objectName()] = label;
    connect(label, SIGNAL(selected()), this, SLOT(labelSelected()));
    row->layout()->addWidget(label);

    label = new CharLabel();
    _labels["Char"] = label;
    connect(label, SIGNAL(selected()), this, SLOT(labelSelected()));
    row->layout()->addWidget(label);

    // keyboard box widget
    _keyboardBoxWidget = new QWidget;
    QLayout * keyboardBoxLayout = new QGridLayout;
    keyboardBoxLayout->setSpacing(0);
    keyboardBoxLayout->setMargin(0);
    keyboardBoxLayout->setContentsMargins(0,0,0,0);
    _keyboardBoxWidget->setLayout(keyboardBoxLayout);
    _keyboardBoxWidget->setFixedHeight(200);
    _mainLayout->addWidget(_keyboardBoxWidget);

    // keyboards
    Keyboard *keyboard = new Keyboard(16, 3);
    keyboard->setObjectName("16");
    connect(keyboard, SIGNAL(pressedButton(QString)), this, SLOT(pressedButton(QString)));
    _keyboards[keyboard->objectName()] = keyboard;

    keyboard = new Keyboard(8, 3);
    keyboard->setObjectName("8");
    connect(keyboard, SIGNAL(pressedButton(QString)), this, SLOT(pressedButton(QString)));
    _keyboards[keyboard->objectName()] = keyboard;

    keyboard = new Keyboard(10, 3);
    keyboard->setObjectName("10");
    connect(keyboard, SIGNAL(pressedButton(QString)), this, SLOT(pressedButton(QString)));
    _keyboards[keyboard->objectName()] = keyboard;

    keyboard = new Keyboard(2, 2);
    keyboard->setObjectName("2");
    connect(keyboard, SIGNAL(pressedButton(QString)), this, SLOT(pressedButton(QString)));
    _keyboards[keyboard->objectName()] = keyboard;

    setKeyboard(tr("10"));
    updateLabels();
}

void MainWindow::pressedButton(const QString & value) {
    Label * label = _labels[sender()->objectName()];
    if (label) {
        QString newText = label->text();
        if (value == "") {
            if (newText.length() > 0) {
                newText = newText.remove(newText.length() - 1, 1);
            }
        }
        else {
            newText = newText + value;
        }

        label->setText(newText);

        // make the number
        _number = label->getNumber();

        // update labels
        updateLabels();
    }
}

void MainWindow::updateLabels() {
    for (Label * label : _labels) {
        label->setNumber(_number);
    }
}

void MainWindow::setKeyboard(const QString &keyboardType) {
    Keyboard *keyboard = _keyboards[keyboardType];

    if (keyboard) {
        if (_currentKeyboard && _currentKeyboard != keyboard) {
            //_keyboardBoxWidget->layout()->removeWidget(_currentKeyboard);

            QLayoutItem * layoutItem = _keyboardBoxWidget->layout()->replaceWidget(_currentKeyboard, keyboard);

            if (layoutItem != 0) {
                delete layoutItem;
                //_currentKeyboard->setHidden(true);
                _currentKeyboard->setParent(0);
            }
            else {
                return;
            }
        }
        else if (_currentKeyboard == 0) {
            _keyboardBoxWidget->layout()->addWidget(keyboard);
        }
        else {
            return;
        }

        qDebug() << keyboardType << "\n";

        _currentKeyboard = keyboard;
        //_currentKeyboard->setHidden(false);
    }
}

void MainWindow::labelSelected() {
    Label * label = (Label *)sender();
    setKeyboard(label->objectName());
}
