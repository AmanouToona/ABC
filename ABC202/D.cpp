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


string solve(int A, int B, ll K, vector<vector<ll>> &dp) {
    if (A == 0 && B == 0) return string("");
    if (B == 0) return string("a") + solve(A - 1, B, K, dp);
    if (A == 0) return string("b") + solve(A, B - 1, K, dp);

    if (K <= dp[A - 1][B]) return string("a") + solve(A - 1, B, K, dp);
    return string("b") + solve(A, B - 1, K - dp[A - 1][B], dp);
}


int main() {
    int A, B;
    ll K;
    cin >> A >> B >> K;

    vector<vector<ll>> dp(A + 1, vector<ll>(B + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <=A; i++) {
        for (int j = 0; j <= B; j++) {
            if (j > 0) dp[i][j] += dp[i][j - 1];
            if (i > 0) dp[i][j] += dp[i - 1][j];
        }
    }

    cout << solve(A, B, K, dp) << endl;

}
