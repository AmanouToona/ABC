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

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<vector<int>> dp(2, vector<int>(N, 1e16));
    for (int i = 0; i < N; i++) {
        dp[1][i] = 0;
    }

    dp[0][0] = A[N - 1];
    dp[1][0] = A[0];
    dp[1][1] = 1;

    for (int i = 2; i < N; i++) {
    }
}