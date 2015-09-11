//
// Created by Francesco Burelli on 11/09/15.
//

#ifndef INC_01CONVERTER_NUMBER_H
#define INC_01CONVERTER_NUMBER_H

#include <string>

using namespace std;

class Number {

public:
    Number(const string & s, int base);
    Number(const uint16_t value = 0);

    static uint64_t unsignedIntWithString(const string & s, int base);
    static string baseStringWithInt(const uint64_t number, int base);

    string baseString(int base);

    const string & binaryString() const;

    const string & hexString() const;

    const string & octalString() const;

    const string & unsignedIntString() const;

    const string & signedIntString() const;

    const string & charString() const;

    uint16_t uint16() const;

    int16_t int16() const;

private:
    string _binaryString;
    string _hexString;
    string _octalString;
    string _unsignedIntString;
    string _signedIntString;
    string _charString;

    uint16_t _uint16;
    int16_t _int16;
};


#endif //INC_01CONVERTER_NUMBER_H
