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


void dfs(vector<int> &judge, int u, vector<vector<int>> & tree) {
    if (judge[u] != -1) {
        return;
    }


    if (tree[u].size() == 0) {
        judge[u] == 0;
        return; 
    }

    if (tree[u].size() == 1 && tree[u][0] == u) {
        judge[u] =2;
        return;
    }

    bool lose = false;
    bool cycle = false;
    for (int v: tree[u]) {
        if (v == u) {
            cycle = true;
            continue;
        }
        dfs(judge, v, tree);
        if (judge[v] == 0) {
            lose = true;
        }
    }

    if (lose) {
        if (cycle) judge[u] = 2;
        else judge[u] = 1;
    } else {
        judge[u] = 0;
    }

}
 


int main() {
    int N;
    cin >> N;
    vector<string> S(N);

    map<string, vector<int>> m;
    for (int i = 0; i < N; i++) {
        cin >> S[i];

        string key = S[i].substr(0, 3);
        m[key].push_back(i);

    }

    vector<vector<int>> graph(N);
    vector<bool> used(N, false);
    queue<int> q;

    for (int i = 0; i < N; i++) {
        if (used[i]) continue;

        q.push(i);
        used[i] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            int s = S[u].size();
            string key = S[u].substr(s - 3, s);

            for (auto v: m[key]) {
                if (used[v] && v != u) continue;
                
                used[v] = true;
                graph[u].push_back(v);
                if (v != u) q.push(v);
            }
        }
    }

    vector<int> judge(N, -1);
    for (int i = 0; i < N; i++) {
        dfs(judge, i, graph);
    }

    for (int i = 0; i < N; i++) {
        if (judge[i] == 0) {
            cout << "Takahashi" << endl;
        } else if (judge[i] == 1) {
            cout << "Aoki" << endl;
        } else {
            cout << "Draw" << endl;
        }
    }
}