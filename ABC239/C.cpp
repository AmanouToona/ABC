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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    vector<int> x{2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> y{1, 2, 2, 1, -1, -2, -2, -1};

    bool ans = false;
    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < x.size(); j++) {
            if (x1 + x[i] == x2 + x[j] && y1 + y[i] == y2 + y[j]) ans = true;
        }
    }

    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
