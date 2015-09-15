//
// Created by Francesco Burelli on 15/09/15.
//

#ifndef INC_01CONVERTER_CHARLABEL_H
#define INC_01CONVERTER_CHARLABEL_H


#include "Label.h"

class CharLabel : public Label {


public:
    CharLabel(QWidget *parent = 0, Qt::WindowFlags f = 0);


    virtual void setNumber(Number number) override;

    virtual Number getNumber() override;
};


#endif //INC_01CONVERTER_CHARLABEL_H
