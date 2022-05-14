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

    set<string> s;
    int ans = 1e6;
    ll ans_score = 0;
    for (int i = 0; i < N; i++) {
        string S;
        ll T;

        cin >> S >> T;

        if (s.count(S)) continue;
        s.insert(S);
        if (T <= ans_score) continue;
        ans_score = T;
        ans = i + 1;
    }
    cout << ans << endl;
}
