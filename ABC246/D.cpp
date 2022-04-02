#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;

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

ll f(ll a, ll b) {
    ll res = a * a * a + a * a * b + a * b * b + b * b * b;
    return res;
}

int main() {
    ll N;
    cin >> N;

    vector<ll> v;
    for (ll i = 0; i < 1E6 + 1; i++) {
        v.push_back(f(i, 0));
    }

    ll l = 0, r = 1E6 + 1;
    while (r - l > 1) {
        ll m = (r + l) / 2;
        if (v[m] > N)
            r = m;
        else
            l = m;
    }

    ll l2 = 0, r2 = l;
    while (r2 - l2 > 1) {
        ll m = (l2 + r2) / 2;
        if (f(m, m) >= N) {
            r2 = m;
        } else
            l2 = m;
    }

    ll ans = LLONG_MAX;
    ll a = r2;
    while (1) {
        if (f(a, 0) >= ans) {
            a++;
            continue;
        }

        ll bl = -1, br = a;
        while (br - bl > 1) {
            ll m = (bl + br) / 2;
            ll t = f(a, m);
            if (t < N)
                bl = m;
            else
                br = m;
        }

        ll t = f(a, br);
        if (t >= N) ans = min<ll>(ans, t);

        a++;
        if (f(a, 0) > ans) {
            break;
        }
    }

    cout << ans << endl;
}
