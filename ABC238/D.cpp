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

        if (a > s) can = false;
        for (int i = 0; i < 61; i++) {
            bool ba = (a >> i) & 1;
            bool bs = (s >> i ) & 1;

            if (ba == 1) {
                if (bs == 0 && carry) can = false;
                if (bs == 1 && !carry) can = false;
                carry = true;
                continue;
            }

            if (carry) {
                if (bs) {carry = false;}
                else {carry = true;}
                continue;
            }

            carry = false;
        }

        if (can) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}