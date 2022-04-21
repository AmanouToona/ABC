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

ll MOD = 998244353;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<ll>> dp(N, vector<ll>(K + 1, 0));
    for (int i = 1; i <= min(M, K); i++) {
        dp[0][i] = 1ll;
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 1; j <= K; j++) {
            for (int k = 1; k <= M; k++) {
                if (j + k > K) break;
                dp[i + 1][j + k] += dp[i][j];
                dp[i + 1][j + k] %= MOD;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= K; i++) {
        ans += dp[N - 1][i];
        ans %= MOD;
    }

    cout << ans << endl;
}
