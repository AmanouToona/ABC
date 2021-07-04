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
    int N, M;
    cin >> N >> M;
    
    vector<ll> A(M), B(M), C(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        A[i]--; B[i]--;
    }

    vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(N, vector<ll>(N, INF)));
    vector<vector<vector<ll>>> dp2(N, vector<vector<ll>>(N, vector<ll>(N, INF)));

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < M; i++) {
            dp[A[i]][B[i]][k] = C[i];
            dp2[A[i]][B[i]][k] = C[i];

        }
    }

    for (int k = 0; k < N; k++) {
        for (int s = 0; s < N; s++) {
            for (int t = 0; t < N; t++) {
                for (int h = 0; h <= k; h++) {
                    dp[s][t][k] = min(dp[s][t][k], dp[s][h][k] + dp[h][t][k]);
                }
                dp2[s][t][k] = min(dp2[s][t][k], dp2[s][k][k] + dp2[k][t][k]);

                if (dp[s][t][k] > dp2[s][t][k]) {
                    cout<< "?" << endl;
                }

            }
        }
    }

    ll ans = 0;
    for (int s = 0; s < N; s++) {
        for (int t = 0; t < N; t++) {
            for (int k = 0; k < N; k++) {
                if (dp[s][t][k] == INF) continue;
                if (s == t) continue;
                ans += dp[s][t][k];
                if (dp[s][t][k] != dp2[s][t][k]) {
                    cout << "?" << endl;
                }
            }
        }
    }

    cout << ans << endl;

}

