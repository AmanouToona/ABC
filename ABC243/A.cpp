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
    int V;
    cin >> V;

    vector<int> U(3);
    for (int i = 0; i < 3; i++) cin >> U[i];

    int i = 0;
    while (true) {
        V -= U[i % 3];
        if (V < 0) break;
        i++;
    }

    if (i % 3 == 0) {
        cout << "F" << endl;
    } else if (i % 3 == 1) {
        cout << "M" << endl;
    } else {
        cout << "T" << endl;
    }
}