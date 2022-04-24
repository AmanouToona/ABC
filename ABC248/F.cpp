#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vii = vector<vector<ll>>;

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
    int N, P;
    cin >> N >> P;

    vector<vii> dp(
        N + 1, vii(N + 2, vi(2, 0)));  // dp[i個まで見た][j本切った][結合状態]

    dp[1][0][0] = 1;  // 1番左が結合している初期化  0: 結合, 1: 切断
    dp[1][1][1] = 1;  // 1番左が切断している初期化

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // 切り方ベースで考える
            // 000: どれも切らない
            dp[i + 1][j][0] += dp[i][j][0];
            dp[i + 1][j][0] += dp[i][j][1];

            dp[i + 1][j][0] %= P;

            // 001
            dp[i + 1][j + 1][0] += dp[i][j][0];

            dp[i + 1][j + 1][0] %= P;

            // 010
            dp[i + 1][j + 1][0] += dp[i][j][0];
            dp[i + 1][j + 1][1] += dp[i][j][1];

            dp[i + 1][j + 1][0] %= P;
            dp[i + 1][j + 1][1] %= P;

            // 011
            dp[i + 1][j + 2][1] += dp[i][j][0];

            dp[i + 1][j + 2][1] %= P;

            // 100
            dp[i + 1][j + 1][0] += dp[i][j][0];

            dp[i + 1][j + 1][0] %= P;

            // 110
            dp[i + 1][j + 2][1] += dp[i][j][0];

            dp[i + 1][j + 2][1] %= P;
        }
    }

    for (int i = 1; i < N; i++) {
        if (i != 1) {
            cout << " ";
        }
        cout << dp[N][i][0];
    }
    cout << endl;
}