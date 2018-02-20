#ifndef L8_RESDROB_H
#define L8_RESDROB_H

#include <cstring>
#include <ostream>
#include "drob.h"

class resdrob : public drob {
private:
    double res;
public:
    resdrob() : drob()
    {
        res = 0;
    }

    resdrob(int a, int b) : drob(a, b)
    {
        res = (double) a / (double) b;
    }

    resdrob(const resdrob &o);

    friend std::ostream &operator<<(std::ostream &os, const resdrob &resdrob1);

    friend resdrob operator+(resdrob &a, resdrob &b);

    friend resdrob operator-(resdrob &a, resdrob &b);

    friend resdrob operator*(resdrob &a, int b);

    friend resdrob operator*(resdrob &a, resdrob &b);

    friend resdrob operator/(resdrob &a, resdrob &b);

    resdrob operator=(resdrob &a);
};


#endif //L8_RESDROB_H
