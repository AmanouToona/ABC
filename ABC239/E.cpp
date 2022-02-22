#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

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

void dfs(vvi &t, int u, int p, vvi &ans, vi &x) {
    if (t[u].size() == 1 && p != -1) {
        ans[u].push_back(x[u]);
        return;
    }

    for (int v : t[u]) {
        if (v == p) continue;
        dfs(t, v, u, ans, x);

        for (int vx : ans[v]) {
            ans[u].push_back(vx);
        }
    }

    ans[u].push_back(x[u]);

    sort(ans[u].rbegin(), ans[u].rend());
    if (ans[u].size() > 20) ans[u].resize(20);
    return;
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vi X(N);
    for (int i = 0; i < N; i++) cin >> X[i];

    vvi t(N, vi());
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        t[a].push_back(b);
        t[b].push_back(a);
    }

    // K の制約から サイズはN * 20以下
    vvi ans(N, vi());
    dfs(t, 0, -1, ans, X);

    for (int i = 0; i < Q; i++) {
        int V, K;
        cin >> V >> K;
        V--;
        K--;
        cout << ans[V][K] << endl;
    }
}
