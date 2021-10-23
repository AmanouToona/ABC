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

    vector<int> p(9, 8);
    for (int i = 0; i < 8; i++) {
        int pp;
        cin >> pp;
        pp --;
        p[pp] = i;
    }


    priority_queue<pair<int, vector<int>>> q;
    q.push(make_pair(0, p));

    fp[p]++;

    while(!q.empty() > 0) {
        auto [c, pp] = q.top();
        q.pop();

        if (pp == goal) {
            ans = c;
            break;
        }

        int empty = 0;
        for (int i = 0; i < 9; i++) {
            if (pp[i] == 8) {
                empty = i;
                break;
            }
        }

        for (auto u: G[empty]) {
            swap(pp[u], pp[empty]);
            if (fp[pp] >= 1) {
                swap(pp[u], pp[empty]);
                continue;
            }
            q.push(make_pair(c + 1, pp));
            fp[pp]++;

            swap(pp[u], pp[empty]);

        }
    }


    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
