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
    vector<pair<int, int>> lr;
    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;
        lr.push_back(make_pair(l, r));
    }

    sort(lr.begin(), lr.end());

    vector<pair<int, int>> ans;
    int l = lr[0].first, r = lr[0].second;
    for (int i = 0; i < N; i++) {
        int l1 = lr[i].first;
        int r1 = lr[i].second;

        if (l1 > r) {
            ans.push_back(make_pair(l, r));
            l = l1;
            r = r1;
        }

        r = max(r, r1);

        if (i == N - 1) {
            ans.push_back(make_pair(l, r));
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}
