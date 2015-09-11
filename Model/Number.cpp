//
// Created by Francesco Burelli on 11/09/15.
//

#include <sstream>
#include <cmath>
#include "Number.h"

uint64_t Number::unsignedIntWithString(const string & s, int base) {
    uint64_t result = 0;
    int p = 0;
    for (int i = s.length() - 1; i >= 0; --i) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            c -= '0';
        }
        else if (c >= 'A' && c <= 'Z') {
            c = c + 10 - 'A';
        }
        else {
            continue;
        }

        result += std::pow(base,p) * (uint64_t)c;

        p++;
    }
    return result;
}

string Number::baseStringWithInt(const uint64_t number, int base) {
    string result;
    uint64_t tmp = number;
    while (true) {
        stringstream ss;
        uint64_t rest = tmp % base;
        if (rest <= 9) {
            ss << rest;
        }
        else {
            ss << (char)('A' + rest - 10);
        }
        result = ss.str() + result;
        if (tmp <= base-1) {
            break;
        }
        tmp /= base;
    }

    return result;
}

const string &Number::binaryString() const {
    return _binaryString;
}

const string &Number::hexString() const {
    return _hexString;
}

const string &Number::octalString() const {
    return _octalString;
}

const string &Number::unsignedIntString() const {
    return _unsignedIntString;
}

const string &Number::signedIntString() const {
    return _signedIntString;
}

const string &Number::charString() const {
    return _charString;
}

uint16_t Number::uint16() const {
    return _uint16;
}

int16_t Number::int16() const {
    return _int16;
}

Number::Number(const string &s, int base)
        : Number(unsignedIntWithString(s, base))
{

}

Number::Number(const uint16_t value) {
    _uint16 = value;

    _binaryString = baseStringWithInt(_uint16, 2);
    _octalString = baseStringWithInt(_uint16, 8);
    _unsignedIntString = baseStringWithInt(_uint16, 10);
    _hexString = baseStringWithInt(_uint16, 16);
}

string Number::baseString(int base) {
    return Number::baseStringWithInt(_uint16, base);
}
