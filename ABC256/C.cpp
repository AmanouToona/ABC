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
    vector<int> h(3), w(3);
    for (int i = 0; i < 3; i++) cin >> h[i];
    for (int i = 0; i < 3; i++) cin >> w[i];
}
