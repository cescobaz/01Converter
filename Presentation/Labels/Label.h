//
// Created by Francesco Burelli on 11/09/15.
//

#ifndef INC_01CONVERTER_LABEL_H
#define INC_01CONVERTER_LABEL_H

#include <QLabel>
#include <Presentation/Keyboards/Keyboard.h>
#include <Model/Number.h>

class Label : public QLabel {
    Q_OBJECT

public:
    Label(int base = 10, QWidget *parent = 0, Qt::WindowFlags f = 0);

    virtual void setNumber(Number number);
    virtual Number getNumber();

signals:
    void selected();

protected:
    virtual void mouseReleaseEvent(QMouseEvent *ev) override;


    virtual bool event(QEvent *e) override;

private:
    int _base;
};


#endif //INC_01CONVERTER_LABEL_H
