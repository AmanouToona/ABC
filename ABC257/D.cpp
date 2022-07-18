#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using tii = tuple<int, int>;

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

bool can_span(vector<tii> s, vector<tii> t, int start, ll train,
              vector<tuple<int, int, int, int>> raw) {
    int n = s.size();
    vector<bool> used(n, false);

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (used[u]) continue;
        used[u] = true;

        int P = get<1>(raw[u]);
        int x = get<2>(raw[u]);
        int y = get<3>(raw[u]);

        int ss = x + y;
        int tt = x - y;

        for (int i = 0; i < n; i++) {
            if (!used[i] && get<0>(s[i]) <= ss + P * train &&
                get<0>(s[i]) >= ss - P * train &&
                get<0>(t[i]) <= tt + P * train &&
                get<0>(t[i]) >= tt - P * train)
                q.push(i);
        }
    }

    for (bool b : used) {
        if (!b) return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    vector<tii> s, t;                       // s, P, i   t, P, i
    vector<tuple<int, int, int, int>> raw;  // i, P, x, y
    int start_point = 0, start_p = 0;

    for (int i = 0; i < N; i++) {
        int x, y, P;
        cin >> x >> y >> P;
        s.push_back(make_tuple(x + y, i));
        t.push_back(make_tuple(x - y, i));
        raw.push_back(make_tuple(i, P, x, y));

        if (start_p < P) {
            start_point = i;
            start_p = P;
        }
    }

    // sort(s.begin(), s.end(),
    //      [&](tii i, tii j) -> bool { return get<0>(i) < get<0>(j); });

    // sort(t.begin(), t.end(),
    //      [&](tii i, tii j) -> bool { return get<0>(i) < get<0>(j); });

    ll ans = 1e18 + 1;
    for (int start = 0; start < N; start++) {
        ll ok = 1e18 + 1, ng = 0;
        while (ok - ng > 1) {
            ll mid = (ok + ng) / 2;

            if (mid == 21) {
                int dum = 1;
            }
            bool can = can_span(s, t, start_point, mid, raw);
            if (can)
                ok = mid;
            else
                ng = mid;
        }
        ans = min<ll>(ans, ok);
    }
    cout << ans << endl;
}
