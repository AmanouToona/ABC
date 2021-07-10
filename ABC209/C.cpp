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

const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;

    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    sort(C.begin(), C.end());
    ll ans = 1;
    for (int i = 0; i < N; i++) {
        ans *= (C[i] - i);
        ans %= MOD;
    }

    cout << ans <<endl;

}
