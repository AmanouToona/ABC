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

ll gcd(ll x, ll y) {
    if (y == 0) return x;
    else return gcd(y, x % y);
}


int const INF = INT_MAX;


int main() {
    int N;
    cin >> N;

    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

    map<pair<int, int>, int> m;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ll g = gcd(abs(X[i] - X[j]), abs(Y[i] - Y[j]));

            int x = (X[i] - X[j]) / g;
            int y = (Y[i] - Y[j]) / g;

            m[make_pair(x, y)] += 1;

            g = gcd(abs(X[j] - X[i]), abs(Y[j] - Y[i]));
            x = (X[j] - X[i]) / g;
            y = (Y[j] - Y[i]) / g;
            m[make_pair(x, y)] += 1;
        }
    }

    cout << m.size() << endl;
}
