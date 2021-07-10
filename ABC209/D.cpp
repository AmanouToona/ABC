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

const int MOD = 1000000007;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> road(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        road[a].push_back(b);
        road[b].push_back(a);
    }

    priority_queue<pair<int, int>> q;
    for (auto a: road[0]) {
        q.push(make_pair(1, a));
    }

    vector<int> town(N);
    town[0] = 1;
    while (!q.empty()) {
        auto [dist, t] = q.top();
        q.pop();

        town[t] = dist + 1;
        for (auto a: road[t]) {
            if (town[a] != 0) continue;
            q.push(make_pair(dist + 1, a));
        }
    }

    for (int i = 0; i < Q; i++) {
        int c, d;
        cin >> c >> d;
        c--;
        d--;

        if (abs(town[c] - town[d]) % 2 == 0) {
            cout << "Town" << endl;
        } else {
            cout << "Road" << endl;
        }
    }

}
