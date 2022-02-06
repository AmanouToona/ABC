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
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        ll a, s;
        cin >> a >> s;

        bool can = true;

        bool carry = false;

        if (s - 2 * a < 0) {
            cout << "No" << endl;
            continue;
        }

        if (((s - 2 * a) & a) == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }


    }
}