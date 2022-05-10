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
    string S, T;
    cin >> S >> T;

    vector<int> res(S.size());
    for (int i = 0; i < S.size(); i++) {
        if (S[i] <= T[i]) res[i] = T[i] - S[i];
        else res[i] = T[i] - S[i] + 26;
    }

    for (int i = 0; i < res.size() - 1; i++) {
        if (res[i] != res[i + 1]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}