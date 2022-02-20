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

    if (a + 1 == b || (a == 1 && b == 10)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}