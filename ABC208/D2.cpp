#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ll const INF = 1001001001;

    int N, M;
    cin >> N >> M;
    
    vector<ll> A(M), B(M), C(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        A[i]--; B[i]--;
    }

    vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(N, vector<ll>(N, INF)));

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < M; i++) {
            dp[A[i]][B[i]][k] = C[i];
        }
    }

    for (int k = 0; k < N; k++) {
        for (int s = 0; s < N; s++) {
            for (int t = 0; t < N; t++) {
                if (s == t) continue;
                dp[s][t][k] = min(dp[s][t][k], dp[s][t][k - 1]);
                dp[s][t][k] = min(dp[s][t][k], dp[s][k][k] + dp[k][t][k]);
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
            }
        }
    }

    cout << ans << endl;

}
