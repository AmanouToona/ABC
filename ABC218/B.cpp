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
    vector<int> P(26);
    for (int i = 0; i < 26; i++) cin >> P[i];
    for (int i = 0; i < 26; i++) P[i]--;

    for (auto p: P) {
        char ans = p + 'a';
        cout << ans;
    }
    cout << endl;
}

