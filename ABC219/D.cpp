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

ll const INF = INT_MAX;


int main() {
    int N;
    cin >> N;

    ll X, Y;
    cin >> X >> Y;

    vector<ll> A(N), B(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(X + 1, vector<ll>(Y + 1, INF)));
    dp[0][0][0] = 0;  // (購入判断を行った弁当, 今の手持ちA, 今の手持ちB) = 最小の購入個数
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= X; j++) {
            for (int k = 0; k <= Y; k++) {
                // 購入する場合
                dp[i + 1][min<ll>(X, j + A[i])][min<ll>(Y, k + B[i])] = min<ll>(dp[i][j][k] + 1, dp[i + 1][min<ll>(X, j + A[i])][min<ll>(Y, k + B[i])]);

                // 購入しない場合
                dp[i + 1][j][k] = min<ll>(dp[i][j][k], dp[i + 1][j][k]);
            }
        }
    }

    if (dp[N][X][Y] == INF) cout << -1 << endl;
    else cout << dp[N][X][Y] << endl;

}
