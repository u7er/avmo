#include <iostream>
#include "resdrob.h"
#include "smeshdrob.h"

using namespace std;

int main() {
    drob a(12, 13);
    cout << a << endl;
    drob b(a);
    cout << a + b << endl;
    cout << a * b << endl;
    a = a * b;
    b = (b * 5);
    a = a - b;
    cout << a << endl;

    resdrob q1(1, 2);
    resdrob q2(1, 2);
    cout << "res" << endl;
    cout << (q1 * q2) << endl;

    cout << "smesh" << endl;
    smeshdrob w1(12, 10);
    cout << w1 << endl;
    return 0;
}
