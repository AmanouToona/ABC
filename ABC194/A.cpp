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
    int a, b;
    cin >> a >> b;
    int c = a + b;

    if (c >= 15 && b >= 8) {
        cout << 1 << endl;
    } else if (c >= 10 && b >= 3) {
        cout << 2 << endl;
    } else if (c >= 3) {
        cout << 3 << endl;
    } else {
        cout << 4 << endl;
    }

    return 0;
}