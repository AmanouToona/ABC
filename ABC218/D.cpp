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


int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> P;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        P.push_back(make_pair(x, y));
    }

    sort(P.begin(), P.end());

    map<int, set<int>> x;
    for (int i = 0; i < N; i++) {
        x[P[i].first].insert(P[i].second);
    }

    map<pair<int, int>, int> y;
    ll ans = 0;
    for (auto [_, S]: x) {
        vector<int> s(S.begin(), S.end());
        sort(s.begin(), s.end());

        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                ans += y[make_pair(s[i], s[j])];
                y[make_pair(s[i], s[j])] ++;
            }
        }
    }

    cout << ans << endl;

}
