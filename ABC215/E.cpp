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
int const mod = 998244353;

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    // n日目まで見た, 参加したコンテストの集合, 最後に参加したコンテスト
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(1 << 10, vector<int>(11, 0)));
    dp[0][0][10] = 1;
    
    // 初期化 は中で行う 配るdp
    // i: i 日目まで見た, j: コンテストの出場実績の組みあわせ, k: 最後に出場したコンテスト
    for (int i = 0; i < N; i++) {
        int c = S[i] - 'A';
        for (int j = 0; j < (1 << 10); j++) {
            for (int k = 0; k < 11; k++) {
                // constest c に出場しない
                dp[i + 1][j][k] += dp[i][j][k];
                dp[i + 1][j][k] %= mod;

                // contest c に出場する
                if (! ((j >> c) & 1)) {
                    dp[i + 1][j | (1 << c)][c] += dp[i][j][k];
                    dp[i + 1][j | (1 << c)][c] %= mod;
                } else if (k == c) {
                    dp[i + 1][j][c] += dp[i][j][k];
                    dp[i + 1][j][c] %= mod;
                }
            }
        }
    }



    int ans = 0;
    for (int j = 0; j < (1 << 10); j++) {
        for (int k = 0; k < 10; k++) {
            ans += dp[N][j][k];
            ans %= mod;
        }
    }

    cout << ans << endl;

}
