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

ll sum_arithmetic(ll n, ll d, ll a) { return (2 * d + (n - 1) * a) * n / 2; }

void solve() {
    int N, M;
    cin >> N >> M;

    ll ans = -INF;
    ll D = 0;  // A の右端
    ll d = 0;  // B の右端
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;

        auto f = [=](ll D, ll d, ll m) -> ll {
            return D + m * d + x * (m + 1) * m / 2;
        };

        if (x >= 0) {
            // 両端のどちらかが最大値
            ans = max<ll>({ans, D + d + x, D + y * d + x * (y + 1) * y / 2});
        } else {
            // 3分探索
            int l = 1, r = y + 1;
            while (r - l > 2) {
                int m1 = (l + r) / 2;
                int m2 = m1 + 1;

                ll fm1 = f(D, d, m1);
                ll fm2 = f(D, d, m2);
                if (fm1 < fm2)
                    l = m1;
                else
                    r = m2;
            }
            ll fl = f(D, d, l);
            ll fm = f(D, d, l + 1);

            ans = max<ll>({ans, fl, fm});
        }

        D += y * d + x * (y + 1) * y / 2;
        d += y * x;
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        solve();
    }
}