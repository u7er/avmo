#ifndef L8_SMESHDROB_H
#define L8_SMESHDROB_H

#include "drob.h"

class smeshdrob : public drob {
private:
    int full;
public:
    smeshdrob();

    smeshdrob(int a, int b);

    smeshdrob(const smeshdrob &o);

    smeshdrob(const drob &o);
    friend std::ostream &operator<<(std::ostream &os, const smeshdrob &smeshdrob1);
};

#endif //L8_SMESHDROB_H
