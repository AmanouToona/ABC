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
    int N, A, X, Y;
    cin >> N >> A >> X >> Y;

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        if (i >= A + 1) {
            ans += Y;
        } else {
            ans += X;
        }
    }

    cout << ans << endl;


}