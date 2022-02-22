#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int MOD = 998244353;

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

inline long long mod(long long a, long long m) { return (a % m + m) % m; }

long long modinv(long long a, long long m) {
    long long x, y;
    extGCD(a, m, x, y);
    return mod(x, m);
}

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

ll sum(ll x) {
    x %= MOD;
    return (1 + x) % MOD * x % MOD * modinv(2, MOD) % MOD;
}

int main() {
    ll N;
    cin >> N;

    ll inv2 = modinv(2, MOD);

    ll ans = 0LL;
    ll l = 1LL;
    while (l <= N) {
        // [l, r)
        ll r = l * 10;
        r = min<ll>(r, N + 1);

        ll len = r - l;
        ans += sum(len);
        ans %= MOD;
        l *= 10;
    }

    cout << ans << endl;
}
