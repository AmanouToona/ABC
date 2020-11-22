#include<bits/stdc++.h>
using namespace std;

int main() {
    long long r1, c1, r2, c2;

    cin >> r1 >> c1 >> r2 >> c2;

    r2 -= r1;
    c2 -= c1;


    r2 = abs(r2);
    c2 = abs(c2);

    if (r2 == 0 && c2 == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (r2 == c2) {
        cout << 1 << endl;
        return 0;
    }

    if (r2 + c2 <= 3) {
        cout << 1 << endl;
        return 0;
    }

    if (r2 + c2 <= 6) {
        cout << 2 << endl;
        return 0;
    }

    if (abs(r2 - c2) <= 3) {
        cout << 2 << endl;
        return 0;
    }

    if ((r2 + c2) % 2 == 0) {
        cout << 2 << endl;
        return 0;
    }

    cout << 3 << endl;
}