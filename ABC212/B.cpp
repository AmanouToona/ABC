#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll pow_ll(ll x, ll y) {
    ll ret = 1;
    while (y > 0) {
        if (y & 1) ret *= x;
        x *= x;
        y >>= 1;
    }
    return ret;
}

int const INF = INT_MAX;


int main() {
    int x1, x2, x3, x4, xin;
    cin >> xin;

    x1 = xin / 1000;
    xin -= x1 * 1000;

    x2 = xin / 100;
    xin -= x2 * 100;

    x3 = xin / 10;
    xin -= x3 * 10;

    x4 = xin;

    if (x1 == x2 && x2 == x3 && x3 == x4) {
        cout << "Weak" << endl;
        return 0;
    }

    if ((x1 + 1) % 10 == x2 && (x2 + 1) % 10 == x3 && (x3 + 1) % 10 == x4) {
        cout << "Weak" << endl;
        return 0;
    }

    cout << "Strong" << endl;
}