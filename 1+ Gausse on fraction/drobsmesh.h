#ifndef L8_DROBSMESH_H
#define L8_DROBSMESH_H

#include "drob.h"

class drobsmesh : public drob{
private:
    double res;
public:
    drobsmesh() : drob()
    {
        res = 0;
    }
    drobsmesh(int a, int b) : drob(a, b) {
        res = (double) a / (double) b;
    }

//    friend drobsmesh operator+(drobsmesh &a, drobsmesh &b);
//    friend drobsmesh operator-(drobsmesh &a, drobsmesh &b);
//    friend drobsmesh operator*(drobsmesh &a, drobsmesh &b);
//    friend drobsmesh operator/(drobsmesh &a, drobsmesh &b);
//
//    drobsmesh operator=(drobsmesh &a);
//
//    friend std::ostream &operator<<(std::ostream &os, const drob &drob1);
};


#endif //L8_DROBSMESH_H
