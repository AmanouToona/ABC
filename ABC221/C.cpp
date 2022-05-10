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
    string N;
    cin >> N;

    ll ans = 0LL;
    for (ll i = 0; i < (1 << N.size()); i++) {
        string a = "", b = "";
        for (int j = 0; j < N.size(); j++) {
            if (i >> j & 1 == 1) a.push_back(N[j]);
            else b.push_back(N[j]);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        ll A= 0, B=0;
        for (int j = 0; j < a.size(); j++) {
            A += 1ll * (a[j] - '0') * pow_ll(10, j);
        }
        for (int j = 0; j < b.size(); j++) {
            B += 1ll * (b[j] - '0') * pow_ll(10, j);
        }

        // cout << "A: " << A << " B: " << B << endl;

        ans = max<ll>(ans, 1LL * A * B);
    }

    cout << ans << endl;

}
