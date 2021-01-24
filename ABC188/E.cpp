# include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<int>> road(N);
    for (int m = 0; m < M; m++){
        int x, y;
        cin >> x >> y;
        road[--x].push_back(--y);
    };

    const int INF = 1001001001;
    vector<int> dp(N, INF * 2);

    for (int i = 0; i < N; i++){
        for(auto j: road[i]){
            dp[j] = min(dp[j], A[i]);
            dp[j] = min(dp[j], dp[i]);
        }
    };

    int ans = - INF;

    for (int i = 0; i < N; i++) {
        ans = max(ans, A[i] - dp[i]);
    }
    cout << ans << endl;
}
