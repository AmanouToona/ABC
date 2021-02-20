#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> cond(M);
    for (int i = 0; i < M; i++) {
        cin >> cond[i].first >> cond[i].second;
        cond[i].first--;
        cond[i].second--;
    }

    int K;
    cin >> K;
    vector<vector<int>> put(K, vector<int>(2));
    for (int i = 0; i < K; i++) {
        cin >> put[i][0] >> put[i][1];
        put[i][0]--;
        put[i][1]--;
    }


    int ans = 0;

    for (int i =0; i <= pow(2, K) - 1; i++) {
        vector<int> dish(N, 0);
        bitset<16> s(i);

        for(int j = 0; j < K; j++) {
            dish[put[j][s[j]]] += 1;
        }
        int _ans = 0;
        for (int i = 0; i < M; i++) {
            if (dish[cond[i].first] != 0 && dish[cond[i].second] != 0) {
                _ans ++;
            }
        }
        ans = max(ans, _ans);

    }

    cout <<ans << endl;
}