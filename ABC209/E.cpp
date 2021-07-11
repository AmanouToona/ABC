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
    int N;
    cin >> N;
    vector<string> S(N);

    map<string, vector<int>> m;  // 頭3文字を key として単語番号を保存
    for (int i = 0; i < N; i++) {
        cin >> S[i];

        string key = S[i].substr(0, 3);
        m[key].push_back(i);

    }

    vector<vector<int>> to(N);  // 逆辺の保存
    vector<int> deg(N);  // 残り次数
    for (int i = 0; i < N; i++) {
        string b = S[i].substr(S[i].size() - 3, S[i].size());

        for (int p: m[b]) {
            to[p].push_back(i);
            deg[i]++;
        }
    }

    vector<int> ans(N);  // word を言った方が  -1: 負け, 0: 不明 or 引き分け, 1: 勝ち
    queue<int> q;

    for (int i = 0; i < N; i++) {
        if (deg[i] == 0) {
            ans[i] = 1;
            q.push(i);
        }
    }

    while (q.size()) {
        int v = q.front();
        q.pop();

        if (ans[v] == 1) {
            for (int u : to[v]) {
                if (ans[u] != 0) continue;
                ans[u] = -1;
                q.push(u);
            }
        } else {
            for (int u: to[v]) {
                if (ans[u] != 0) continue;
                deg[u]--;
                if (deg[u] == 0) {
                    ans[u] = 1;
                    q.push(u);
                }
            }
        }
    }


    for (int i = 0; i < N; i++) {
        if (ans[i] == 1) {
            cout << "Takahashi" << endl;
        } else if (ans[i] == -1) {
            cout << "Aoki" << endl;
        } else {
            cout << "Draw" << endl;
        }
    }

}

/*
3
aaabbb
bbbccc
cccaaa
*/

