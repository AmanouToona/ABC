#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;

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
    int N, M;
    cin >> N >> M;

    vector<vector<int>> edge;
    map<pair<int, int>, int> cost;
    map<pair<int, int>, int> m;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a > b) {
            int t = a;
            a = b;
            b = t;
        }

        edge[a].push_back(b);
        edge[b].push_back(a);
        cost[make_pair(a, b)] = -c;
        m[make_pair(a, b)] = i + 1;
    }

    priority_queue<pair<int, pair<int, int>>> q;
    for (int v : edge[1]) {
        q.push(make_pair(cost[make_pair(1, v)], make_pair(1, v)));
    }

    vector<bool> fp(N + 1, false);
    vector<int> ans;
    fp[1] = true;
    while (!q.empty()) {
        auto [c, e] = q.top();
        q.pop();

        auto [u, v] = e;
        fp[v] = true;

        if (u < v) {
            ans.push_back(m[make_pair(u, v)]);
        } else {
            ans.push_back(m[make_pair(v, u)]);
        }

        for (int vv : edge[v]) {
            if (fp[vv]) continue;
            int c;
            if (vv < v) {
                c = cost[make_pair(vv, v)];
            } else {
                c = cost[make_pair(v, vv)];
            }
            q.push(make_pair(c, make_pair(v, vv)));
        }
    }

    for (int i = 0; i < N - 1; i++) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}