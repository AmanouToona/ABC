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
    int N;
    cin >> N;
    vector<int> X(N), C(N);
    for (int i = 0; i < N; i++) cin >> X[i];
    for (int i = 0; i < N; i++) X[i]--;
    for (int i = 0; i < N; i++) cin >> C[i];

    vector<int> state(N, 0);
    // 0: not visited
    // 1: visited (calculating)
    // 2: visited (calculated)
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (state[i] != 0) continue;

        vector<int> vs;
        auto dfs = [&](auto f, int v) {
            if (state[v] == 2) return -1;
            if (state[v] == 1) return v;

            state[v] = 1;
            int r = f(f, X[v]);

            state[v] = 2;
            if (r == -1) return -1;
            vs.push_back(C[v]);
            if (r == v) return -1;
            return r;
        };

        dfs(dfs, i);

        if (vs.size() == 0) continue;
        ans += *min_element(vs.begin(), vs.end());
    }
    cout << ans << endl;
}