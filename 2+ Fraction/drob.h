#ifndef L8_DROB_H
#define L8_DROB_H

#include <bits/stdc++.h>

class drob {
protected:
    int chisl, znam;

    int gcd(int a, int b);

public:
    drob();

    drob(int c, int z);

    drob(const drob &o) : drob(o.chisl, o.znam)
    {
    }

    int getChisl();

    int getZnam();

    void setChisl(int chisl);

    void setZnam(int znam);

    friend std::ostream &operator<<(std::ostream &os, const drob &drob1);

    drob operator+(drob &a);

    drob operator-(drob &a);

    drob operator*(drob &a);

    drob operator/(drob &a);

    drob operator=(const drob &a);

    drob operator*(int a);
};


#endif //L8_DROB_H
