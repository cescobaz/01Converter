//
// Created by Francesco Burelli on 11/09/15.
//

#ifndef INC_01CONVERTER_MAINWINDOW_H
#define INC_01CONVERTER_MAINWINDOW_H

#include <QMainWindow>
#include "Labels/Label.h"
#include <QLayout>
#include <Model/Number.h>
#include "Keyboards/Keyboard.h"
#include <QMap>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:

    MainWindow(QWidget *parent = 0);

    void setKeyboard(const QString & keyboardType);

private:
    Number _number;

    QLayout *_mainLayout;

    QWidget *_keyboardBoxWidget;
    Keyboard *_currentKeyboard;

    //
    QMap<QString,Label*> _labels;
    QMap<QString,Keyboard*> _keyboards;

private slots:
    void labelSelected();
    void pressedButton(const QString & value);
    void updateLabels();
};


#endif //INC_01CONVERTER_MAINWINDOW_H
