#ifndef L8_DROB_H
#define L8_DROB_H

#include <bits/stdc++.h>

using namespace std;

class Fraction {
protected:
    uint32_t whole; // whole
    uint32_t num; // numerator
    uint32_t denum; // denumirator
    bool sign; // sign

public:
    Fraction();
    Fraction(int32_t n, int32_t d);
    Fraction(int32_t w, int32_t n, int32_t d);

    Fraction operator + (const Fraction &fraction);
    Fraction operator - (const Fraction &fraction);
    Fraction operator * (const Fraction &fraction);
    Fraction operator / (const Fraction &fraction);
    Fraction operator = (const Fraction &fraction);

    friend ostream &operator<<(std::ostream &os, const Fraction &fraction);
    friend istream &operator>>(std::istream &is, Fraction &fraction);
};


#endif //L8_DROB_H
