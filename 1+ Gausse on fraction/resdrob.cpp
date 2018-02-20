#include "resdrob.h"

resdrob::resdrob(const resdrob &o)
{
    memcpy(this, &o, sizeof(resdrob));

}

std::ostream &operator<<(std::ostream &os, const resdrob &resdrob1)
{
    os << resdrob1.res;
    return os;
}

resdrob resdrob::operator=(resdrob &a)
{
    memcpy(this, &a, sizeof(resdrob));
    return *this;
}

resdrob operator+(resdrob &a, resdrob &b)
{
    drob c((drob) a);
    drob f((drob) b);
    c = c + f;
    return resdrob(c.getChisl(), c.getZnam());
}

resdrob operator-(resdrob &a, resdrob &b)
{
    resdrob c(-b.chisl, b.znam);
    return a + c;
}

resdrob operator*(resdrob &a, resdrob &b)
{
    return resdrob(a.chisl * b.chisl, a.znam * b.znam);
}

resdrob operator/(resdrob &a, resdrob &b)
{
    resdrob c(b.znam, b.chisl);
    return a * c;
}

resdrob operator*(resdrob &a, int b)
{
    return resdrob(a.chisl * b, a.znam);
}
