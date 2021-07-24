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

ll const MOD = 1e9 + 7;

int main() {
    string S;
    cin >> S;

    string chokudai = "chokudai";

    vector<vector<ll>> dp(8, vector<ll>(S.size(), 0));

    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'c') {
            dp[0][i]++;
        }
        if (i == 0) continue;
        dp[0][i] += dp[0][i - 1];
    }

    for (int i = 1; i < 8; i++) {
        for (int j = 0; j < S.size(); j++) {
            if (S[j] == chokudai[i]) {
                dp[i][j] = dp[i - 1][j];
            }
            if (j == 0) continue;
            dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }

    cout << dp[7][S.size() - 1] << endl;




}
