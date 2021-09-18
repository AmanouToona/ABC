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
    int X;
    cin >> X;

    if (X >= 90) {
        cout << "expert" << endl;
    } else if (X >= 70) {
        cout << 90 - X << endl;
    } else if (X >= 40) {
        cout << 70 - X << endl;
    } else {
        cout << 40 - X << endl;
    }
}