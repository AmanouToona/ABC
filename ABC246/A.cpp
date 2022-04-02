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
    vector<int> x(3), y(3);
    for (int i = 0; i < 3; i++) {
        cin >> x[i] >> y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int x_a, y_a;
    if (x[0] == x[1]) {
        x_a = x[2];
    } else {
        x_a = x[0];
    }

    if (y[0] == y[1]) {
        y_a = y[2];
    } else {
        y_a = y[0];
    }

    cout << x_a << " " << y_a << endl;
}