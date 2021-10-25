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

map <vector<int>, int> fp;
int ans = INF;
vector<int> goal{0, 1, 2, 3, 4, 5, 6, 7, 8};


int main() {
    int M;
    cin >> M;

    vector<vector<int>> G(9, vector<int>());
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> P(9, 8);
    for (int i = 0; i < 8; i++) {
        int p;
        cin >> p;
        p--;
        P[p] = i;
    }

    auto compare = [](pair<int, vector<int>> const&l, pair<int, vector<int>> const&r) -> bool {return l.first > r.first;};
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, decltype(compare)> q(compare);
    q.push(make_pair(0, P));
    fp[P]++;

    int ans = INF;
    while(!q.empty()) {
        auto [c, p] = q.top();
        q.pop();

        if (p == goal) {
            ans = c;
            break;
        }

        int v;
        for (int i = 0; i <= 8; i++) {
            if (p[i] == 8) v = i;
        }

        for (int u: G[v]) {
            vector<int> p_nxt = p;
            swap(p_nxt[u], p_nxt[v]);
            if (fp.count(p_nxt) != 0) continue;

            q.push(make_pair(c + 1, p_nxt));
            fp[p_nxt]++;
        }
    }

    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}
