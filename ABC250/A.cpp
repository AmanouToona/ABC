
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
    int H, W, R, C;
    cin >> H >> W >> R >> C;

    int ans = 0;
    if (H > R) ans++;
    if (R > 1) ans++;
    if (W > C) ans++;
    if (C > 1) ans++;
    cout << ans << endl;
}