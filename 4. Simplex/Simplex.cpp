#include <bits/stdc++.h>
#include "Fraction.h"

using namespace std;

int Dis_comp(Fraction a, Fraction b) {
    if(a.m_denominator != b.m_denominator) {
        a.m_numerator *= b.m_denominator;
        b.m_numerator *= a.m_denominator;
    }
    if(a.m_numerator < b.m_numerator) return 1;
    else if(a.m_numerator == b.m_numerator && a.m_denominator == b.m_denominator) return 0;
    else return -1;
}

int main() {
    Fraction min;
    ifstream in("simplex.txt");
    int basis_num = 0, n = 0;
    in >> basis_num >> n;
    vector <Fraction> Q(n);
    for(int i = 0; i < n; ++i) {
        in >> Q[i].m_numerator;
        Q[i].m_numerator = -Q[i].m_numerator;
        Q[i].m_denominator = 1;
    }
    Fraction matrix[basis_num][n];
    for(int i = 0; i < basis_num; ++i) {
        for(int j = 0; j < n; ++j) {
            in >> matrix[i][j].m_numerator;
            matrix[i][j].m_denominator = 1;
        }
    }
    for(int i = 0; i < basis_num; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < n; ++i) {
        cout << Q[i]<< " ";
    }
    cout <<  endl<< endl;
    Fraction temp;
    int index;
    while(1) {
        temp.m_numerator = 0;
        index = 0;
        for(int i = 0; i < n; ++i) {
            if(Dis_comp(temp, Q[i]) == -1) {
                temp = Q[i];
                index = i;
            }
        }
        if(temp.m_numerator == 0) break;
        min.m_numerator = -1000000;
        Fraction cont;
        int indey = 0;
        for(int i = 0; i < basis_num; ++i) {
            cont = matrix[i][n-1]/matrix[i][index];
            if(Dis_comp(min, cont) == 1 && cont.m_numerator > 0) {
                min = cont;
                indey = i;
            }
        }
        Fraction lama = matrix[indey][index];
        for(int i = 0; i < n; ++i) {
            matrix[indey][i] = matrix[indey][i] / lama;
        }
        Fraction sun;
        for(int i = 0; i < basis_num; ++i) {
            if(i == indey) continue;
            lama = -matrix[i][index];
            for(int j = 0; j < n; ++j) {
                matrix[i][j] = matrix[i][j]+ matrix[indey][j]*(lama);
            }
        }
        lama = -Q[index];
        for(int j = 0; j < n; ++j) {
            Q[j] = Q[j]+ matrix[indey][j]*(lama);
        }
        for(int i = 0; i < basis_num; ++i) {
            for(int j = 0; j < n; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        for(int i = 0; i < n; ++i) {
            cout << Q[i]<< " ";
        }
        cout << endl << endl;
    }
    return 0;
}
