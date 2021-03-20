#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> ab(M);
    for (int i = 0; i < M; i++) {
        cin >> ab[i].first >> ab[i].second;
    }

    int K;
    cin >> K;
    vector<pair<int, int>> cd(K);
    for (int i = 0; i < K; i++) {
        cin >> cd[i].first >> cd[i].second;
    }

    int ans = 0;
    int k2 = 1 << K;
    for (int i = 0 ; i < k2; i++) {
        vector<int> dish(N + 1);
        for (int s = 0; s < K; s++) {
            if (i >> s & 1) {
                dish[cd[s].first]++;
            } else {
                dish[cd[s].second]++;
            }
        }
        int now = 0;
        for (int i = 0; i < M; i++) {
            if (dish[ab[i].first] == 0) continue;
            if (dish[ab[i].second] == 0) continue;
            now++;
        }
        ans = max(ans, now);
    }

    cout << ans << endl;
    return 0;

}