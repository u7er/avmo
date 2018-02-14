#include "smeshdrob.h"

std::ostream &operator<<(std::ostream &os, const smeshdrob &smeshdrob1)
{
    os  << smeshdrob1.full << "(" << smeshdrob1.chisl << '/' << smeshdrob1.znam << ")";
    return os;
}

smeshdrob::smeshdrob()
{
    chisl = znam = full = 0;
}

smeshdrob::smeshdrob(int a, int b) : drob(a, b)
{
    full = chisl / znam;
    chisl %= znam;
}

smeshdrob::smeshdrob(const smeshdrob &o) : smeshdrob(o.chisl, o.znam)
{

}

smeshdrob::smeshdrob(const drob &o) : drob(o)
{
    full = chisl / znam;
    chisl %= znam;
}
