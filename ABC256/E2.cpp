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

// SCC による別解
vector<int> groupList, rorder;
vector<bool> used;

int groupNo = 0;

void dfs(int u, vvi& g) {
    used[u] = true;
    for (int v : g[u]) {
        if (used[v]) continue;
        dfs(v, g);
    }
    rorder.push_back(u);
}

void rdfs(int u, vvi& rg) {
    groupList[u] = groupNo;
    for (int v : rg[u]) {
        if (groupList[v] != -1) continue;
        rdfs(v, rg);
    }
    return;
}

int main() {
    int N;
    cin >> N;
    vector<int> X(N), C(N);
    for (int i = 0; i < N; i++) cin >> X[i];
    for (int i = 0; i < N; i++) X[i]--;
    for (int i = 0; i < N; i++) cin >> C[i];

    groupList.resize(N);
    for (int i = 0; i < N; i++) groupList[i] = -1;
    used.resize(N);
    for (int i = 0; i < N; i++) used[i] = false;

    vvi g(N), rg(N);
    for (int i = 0; i < N; i++) {
        g[i].push_back(X[i]);
        rg[X[i]].push_back(i);
    }

    for (int i = 0; i < N; i++) {
        if (used[i]) continue;
        dfs(i, g);
    }

    reverse(rorder.begin(), rorder.end());

    for (int r : rorder) {
        if (groupList[r] != -1) continue;
        rdfs(r, rg);
        groupNo++;
    }

    vvi cost(N);
    for (int i = 0; i < N; i++) {
        int g = groupList[i];
        cost[g].push_back(C[i]);
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (cost[i].size() <= 1) continue;
        ans += *min_element(cost[i].begin(), cost[i].end());
    }
    cout << ans << endl;
}