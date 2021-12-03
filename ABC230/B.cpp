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
    string S;
    cin >> S;

    string T = "oxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxx";

    bool yes = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < S.size(); j++) {
            if (T[i + j] != S[j]) break;
            if (j == S.size() - 1) yes = true;
        }
    }

    if (yes) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}