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


void dfs(vector<vector<int>> &road, vector<bool> &used, int u, vector<int> &ans) {

    for (int v: road[u]) {
        if (used[v]) continue;

        ans.push_back(u);
        used[v] = true;

        dfs(road, used, v, ans);

    }
    ans.push_back(u);
}


int main() {
    int N;
    cin >> N;

    vector<vector<int>> road(N, vector<int>());
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        road[a].push_back(b);
        road[b].push_back(a);
    }

    for (int i = 0; i < N - 1; i++) {
        sort(road[i].begin(), road[i].end());
    }

    vector<bool> used(N, false);
    used[0] = true;
    vector<int> ans;
    dfs(road, used, 0, ans);


    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1;
        if (i == ans.size() - 1) continue;
        cout << " ";
    }

    cout << endl;

}
