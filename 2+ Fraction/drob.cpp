#include "drob.h"

drob::drob()
{
    chisl = znam = 0;
}


std::ostream &operator<<(std::ostream &os, const drob &drob1)
{
    os << drob1.chisl << '/' << drob1.znam;
    return os;
}


drob::drob(int c, int z)
{
    int t = gcd(c, z);
    chisl = c / t;
    znam = abs(z / t);
}

int drob::getChisl()
{
    return chisl;
}

int drob::getZnam()
{
    return znam;
}

int drob::gcd(int a, int b)
{
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

void drob::setChisl(int chisl)
{
    drob::chisl = chisl;
}

void drob::setZnam(int znam)
{
    drob::znam = znam;
}

drob drob::operator+(drob &a)
{
    return drob(chisl * a.znam + znam * a.chisl, znam * a.znam);
}

drob drob::operator*(drob &a)
{
    int u = chisl * a.chisl;
    int d = znam * a.znam;
    int t = gcd(u, d);
    return drob(u / t, d / t);
}

drob drob::operator*(int a)
{
    chisl *= a;
    int t = gcd(chisl, znam);
    return drob(chisl / t, znam / t);
}

drob drob::operator-(drob &a)
{
    drob b(a * (-1));
    return (*this + b);
}

drob drob::operator/(drob &a)
{
    drob c(a.znam, a.chisl);
    return *this * c;
}

drob drob::operator=(const drob &a)
{
    chisl = a.chisl;
    znam = a.znam;
}
