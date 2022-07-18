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

    map<int, ll> m;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        m[a]++;
    }

    ll comp_ans = 0LL;
    for (auto [_, value] : m) {
        if (value < 2) continue;
        if (value == 2) {
            comp_ans += N - 2;
            continue;
        }
        comp_ans += 1LL * value * (value - 1) / 2 * (N - value) +
                    value * (value - 1) / 2 * (value - 2) / 3;
    }

    ll ans = 1LL * N * (N - 1) / 2 * (N - 2) / 3 - comp_ans;

    cout << ans << endl;
}
