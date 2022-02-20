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

void solve(vector<pair<int, int>> &dp, vector<vector<int>> &t, int u) {
    if (dp[u].first != 0 && dp[u].second != 0) return;

    int l = INF, r = 0;
    for (int v : t[u]) {
        solve(dp, t, v);
        l = min(dp[v].first, l);
        r = max(dp[v].second, r);
    }

    dp[u] = make_pair(l, r);
    return;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> tree(N, vector<int>());
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<vector<int>> t(N, vector<int>());
    vector<bool> f(N, false);
    queue<int> q;
    f[0] = true;
    for (int i = 0; i < tree[0].size(); i++) {
        q.push(tree[0][i]);
        t[0].push_back(tree[0][i]);
        f[tree[0][i]] = true;
    }

    vector<pair<int, int>> dp(N, pair<int, int>());
    int leaf_no = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        bool leaf = true;
        for (int i = 0; i < tree[u].size(); i++) {
            int v = tree[u][i];
            if (f[v]) continue;
            leaf = false;
            q.push(v);
            f[v] = true;
            t[u].push_back(v);
        }
        if (leaf) {
            dp[u] = make_pair(leaf_no, leaf_no);
            leaf_no++;
        }
    }

    solve(dp, t, 0);
    for (int i = 0; i < N; i++) {
        cout << dp[i].first << " " << dp[i].second << endl;
    }
}