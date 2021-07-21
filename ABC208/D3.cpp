#include <bits/stdc++.h>
using namespace std;
using ll = long long;
  
 
int main() {
    int N, M;
    cin >> N >> M;
    ll const INF = 1001001001001001;

    
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
        }
    }
    
    ll ans = 0;
    for (int k = 0; k < N; k++) {
        for (int s = 0; s < N; s++) {
            for (int t = 0; t < N; t++) {
                if (k > 0) {
                    dp[s][t][k] = min(dp[s][t][k], dp[s][t][k - 1]);
                    dp[s][t][k] = min(dp[s][t][k], dp[s][k][k - 1] + dp[k][t][k - 1]);
                }
                dp[s][t][k] = min(dp[s][t][k], dp[s][k][k] + dp[k][t][k]);  // ここの値が k -1, k でことなるのはどんな時？
                if (s == t) continue;
                if (dp[s][t][k] == INF) continue;
                ans += dp[s][t][k];
            }
        }
    }
 
    cout << ans << endl;
 
}