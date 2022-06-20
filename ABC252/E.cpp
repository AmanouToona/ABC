#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;
#define mp(a, b) make_pair(a, b)

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

    vector<vector<int>> edge(N + 1, vector<int>());
    map<pair<int, int>, int> cost;
    map<pair<int, int>, int> m;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        edge[a].push_back(b);
        edge[b].push_back(a);

        cost[mp(a, b)] = -c;
        cost[mp(b, a)] = -c;

        m[mp(a, b)] = i + 1;
        m[mp(b, a)] = i + 1;
    }

    priority_queue<pair<float, pair<int, int>>> q;
    for (int v : edge[1]) {
        q.push(mp(cost[mp(1, v)], mp(1, v)));
    }

    vector<bool> fp(N + 1, false);
    fp[1] = true;
    vector<int> ans;
    int count = 0;

    while (!q.empty()) {
        auto [c, e] = q.top();
        q.pop();
        count++;

        auto [parent, u] = e;
        if (fp[u]) continue;
        fp[u] = true;

        if (u < parent) {
            ans.push_back(m[mp(u, parent)]);
        } else {
            ans.push_back(m[mp(parent, u)]);
        }

        for (int v : edge[u]) {
            if (fp[v]) continue;
            int c;
            if (v < u) {
                c = cost[mp(v, u)];
            } else {
                c = cost[mp(u, v)];
            }

            q.push(mp(c - count * 0.00001, mp(u, v)));
        }
    }

    for (int i = 0; i < N - 1; i++) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}