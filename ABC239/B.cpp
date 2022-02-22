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
    ll X;
    cin >> X;

    if (X < 0 && X % 10 != 0) {
        cout << X / 10 - 1 << endl;
    } else {
        cout << X / 10 << endl;
    }
}