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


int main() {
    ll N;
    cin >> N;

    map<ll, bool> mp;
    ll count = 0;

    for (long double a = 2; a <= sqrt(N); a++) {
        for (long double b = 2; b <= log2(N); b++) {
            if (pow_ll(a, b) > N) break;
            long double ab = pow_ll(a, b);

            if (ab > N) break;

            if (mp.count(ab)) continue;
            mp[ab] = true;
            count++;

        }
    }

    cout << (N - count) << endl;

}