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
    ll N;
    cin >> N;

    int k = 0;
    ll n = 2;
    while (n <= N) {
        n *= 2;
        k ++;
    }

    cout << k << endl;
}
