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
int leaf_no = 1;

void dfs(vector<vector<int>> &g, int u, int p, vector<pair<int, int>> &dp) {
    if (g[u].size() == 1 && p != -1) {
        dp[u] = make_pair(leaf_no, leaf_no);
        leaf_no++;
        return;
    }

    for (int v : g[u]) {
        if (v == p) continue;
        dfs(g, v, u, dp);
    }
    return;
}

void dfs2(vector<vector<int>> &g, vector<pair<int, int>> &dp, int u, int p) {
    if (dp[u].first == dp[u].second) return;

    int l = INF, r = -1;
    for (int v : g[u]) {
        if (v == p) continue;
        dfs2(g, dp, v, u);
        l = min(l, dp[v].first);
        r = max(r, dp[v].second);
    }

    dp[u] = make_pair(l, r);
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> g(N, vector<int>());
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<pair<int, int>> dp(N, pair<int, int>());
    for (int i = 0; i < N; i++) dp[i] = make_pair(INF, -1);
    dfs(g, 0, -1, dp);
    dfs2(g, dp, 0, -1);

    for (int i = 0; i < N; i++) {
        cout << dp[i].first << " " << dp[i].second << endl;
    }
}