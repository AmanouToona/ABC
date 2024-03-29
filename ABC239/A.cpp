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
    ll H;
    cin >> H;

    double ans = 1.0 * sqrt(H) * sqrt(12800000 + H);
    cout << fixed << setprecision(10) << ans << endl;
}
