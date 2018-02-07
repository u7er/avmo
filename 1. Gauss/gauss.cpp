#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream ist("gauss_input.txt");
    ofstream ost("gauss_output.txt");
    int x, y;
    ist >> x;
    y = x + 1;

    double arr[x][y];
    double ans[x];
    double temp1, temp2, temp3, temp4;
    for (int i = 0; i < x; ++i)
        for (int j = 0; j < y; ++j)
            ist >> arr[i][j];

    for (int i = 0; i < y - 2; ++i) {
        for (int j = i + 1; j < x; ++j) {
            temp1 = arr[j][i] / arr[i][i];
            for (int k = 0; k < y; ++k) {
                arr[j][k] -= temp1 * arr[i][k];
            }
        }
        ost << "STEP " << i << endl;
        for (int out1 = 0; out1 < x; ++out1) {
            for (int out2 = 0; out2 < y; ++out2)
                ost << arr[out1][out2] << " ";
            ost << endl;
        }
        ost << endl;
    }
    for (int i = x - 1; i >= 0; --i) {
        ans[i] = arr[i][y - 1] / arr[i][i];
        for (int j = 0; j < i; ++j) {
            arr[j][y - 1] -= arr[j][i] * ans[i];
        }
    }

    ost << "ANSWER:" << endl;
    for (int i = 0; i < x; ++i) {
        ost << ans[i] << " ";
    }
    return 0;
}
