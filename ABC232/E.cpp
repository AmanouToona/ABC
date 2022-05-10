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

ll mod = 998244353;


int main() {
    int H, W, K;
    cin >> H >> W >> K;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ll h = 1LL;
    ll w = 1LL;

    for (int k = 0; k < K - 1 ; k++) {
        ll nh = w * H - w;
        ll nw = h * W - h;

        nw %= mod;
        nh %= mod;

        h = nh;
        w = nw;
    }

    ll ans = h + w;
    ans %= mod;
    cout << ans << endl;

}