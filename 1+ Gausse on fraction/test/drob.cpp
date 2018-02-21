#include "drob.h"

#include <algorithm>

using namespace std;

Fraction::Fraction(){
    this->whole = 0;
    this->num = 0;
    this->denum = 0;
    this->sign = false;
}

Fraction::Fraction(int32_t n, int32_t d){
    if(n < 0 || d < 0){
        sign = true;
        n = abs(n);
        d = abs(d);
    }

    if (n > d) {
        this->whole = n / d;
        n %= this->whole;
    }

    uint32_t temp = __gcd(n, d);

    this->num = n / temp;
    this->denum = d / temp;
}

Fraction::Fraction(int32_t w, int32_t n, int32_t d){
    if(n < 0 || d < 0 || w < 0){
        sign = true;
        n = abs(n);
        d = abs(d);
        w = abs(w);
    }
    this->whole = w;

    if (n > d) {
        this->whole += n / d;
        n %= d;
    }

    uint32_t temp = __gcd(n, d);

    this->num = n / temp;
    this->denum = d / temp;
}


