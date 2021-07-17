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


int main() {
    ll H, W, C;
    cin >> H >> W >> C;

    vector<vector<ll>> A(H, vector<ll>(W));
    for (ll h = 0; h < H; h++) {
        for (ll w = 0; w < W; w++) {
            cin >> A[h][w];
        }
    }

    ll ans = LLONG_MAX;
    for (ll i = 0; i < 2; i++) {
        vector<vector<ll>> dp(H, vector<ll>(W, INT_MAX));
        dp[0][0] = A[0][0];
        for (ll h = 0; h < H; h++) {
            for (ll w = 0; w < W; w++) {
                if (h > 0) dp[h][w] = min<ll>(dp[h - 1][w], A[h][w] - 1ll * C * (h + w));
                if (w > 0) dp[h][w] = min<ll>({dp[h][w - 1], A[h][w] - 1ll * C * (h + w), dp[h][w]});

                if (h + 1 < H) ans = min<ll>(ans, dp[h][w] + A[h + 1][w] + 1ll * C * (h + w + 1));
                if (w + 1 < W) ans = min<ll>({ans, dp[h][w] + A[h][w + 1] + 1ll * C * (h + w + 1)});
            }
        }

        reverse(A.begin(), A.end());
    }

    cout << ans << endl;   
}
