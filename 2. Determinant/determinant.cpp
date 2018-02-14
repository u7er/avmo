#include <bits/stdc++.h>

using namespace std;

double Determinant(vector<vector<double> > a){
    const double EPS = 1E-9;
    int n = a.size();

    double det = 1;
    for (int i=0; i<n; ++i) {
        int k = i;
        for (int j=i+1; j<n; ++j)
            if (abs (a[j][i]) > abs (a[k][i]))
                k = j;
        if (abs (a[k][i]) < EPS) {
            det = 0;
            break;
        }
        swap (a[i], a[k]);
        if (i != k)
            det = -det;
        det *= a[i][i];
        for (int j=i+1; j<n; ++j)
            a[i][j] /= a[i][i];
        for (int j=0; j<n; ++j)
            if (j != i && abs (a[j][i]) > EPS)
                for (int k=i+1; k<n; ++k)
                    a[j][k] -= a[i][k] * a[j][i];
    }

    return det;
}

int main(){
    ifstream ist("input.txt");
    vector< vector <double> > arr;
    int sz;
    ist >> sz;
    double temp;
    arr.resize(sz);
    for (auto &i: arr) {
        i.resize(sz);
        for (auto &j: i) {
            ist >> j;
        }
    }
    cout << Determinant(arr);
    return 0;
}
