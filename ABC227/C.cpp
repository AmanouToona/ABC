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
    ll N;
    cin >> N;

    ll ans = 0;
    for (ll a = 1; a * a * a <= N; a++) {
        for (ll b = a; a * b * b <= N; b++) {
            ans += max<ll>(N / b / a - b + 1, 0);
        }
    }

    cout << ans << endl;
}

