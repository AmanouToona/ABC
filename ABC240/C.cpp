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
    int N, X;
    cin >> N >> X;

    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    }

    vector<vector<bool>> dp(N + 1, vector<bool>(X + 1, false));
    dp[0][0] = true;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= X; j++) {
            if (!dp[i][j]) continue;
            if (j + a[i] <= X) dp[i + 1][j + a[i]] = true;
            if (j + b[i] <= X) dp[i + 1][j + b[i]] = true;
        }
    }

    if (dp[N][X]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
