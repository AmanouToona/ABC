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


ll search(ll N, ll i) {
    ll left = i;
    ll right = N + 1;

    while (right - left > 1) {
        ll mid = left + (right - left) / 2;
        if (N / mid < N / i) right = mid;
        else left = mid;
    }

    return left;

}


int main() {
    ll N;
    cin >> N;

    ll i = 1;
    ll ans = 0;
    while (i <= N) {
        ll temp = search(N, i);
        ans += N / i * (temp - i + 1);
        i = temp + 1;
    }

    cout << ans << endl;

}