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
    string S;
    cin >> S;

    vector<int> isin(10, false);
    for (char s : S) {
        isin[s - '0'] = true;
    }

    for (int i = 0; i < 10; i++) {
        if (!isin[i]) {
            cout << i << endl;
            return 0;
        }
    }
}