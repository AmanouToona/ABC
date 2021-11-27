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
    int N, W;
    cin >> N >> W;

    vector<pair<ll, ll>> cheese(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        cheese[i] = make_pair(-a, b);
    }

    sort(cheese.begin(), cheese.end());

    ll score = 0LL;
    int i = 0;
    while (W > 0) {
        if (cheese[i].second <= W) {
            score -= cheese[i].first * cheese[i].second;
        } else {
            score -= cheese[i].first * W;
        }
        W -= cheese[i].second;
        i++;
        if (i >= cheese.size()) break;
    }

    cout << score << endl;

}
