//
// Created by Francesco Burelli on 11/09/15.
//

#ifndef INC_01CONVERTER_KEYBOARD_H
#define INC_01CONVERTER_KEYBOARD_H


#include <QWidget>
#include <QGridLayout>

class Keyboard : public QWidget {
    Q_OBJECT

public:
    Keyboard(const QVector<QString> & values, int columns = 3, QWidget * parent = 0);
    Keyboard(int base = 10, int columns = 3, QWidget * parent = 0);

signals:
    void pressedButton(const QString & value);


private slots:
    void pressedButton();
};


#endif //INC_01CONVERTER_KEYBOARD_H
