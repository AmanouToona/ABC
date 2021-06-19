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
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll ans1 = 1LL * N * (N - 1) / 2; // N C 2

    map<int, int> dup;
    for (auto a: A) {
        if (dup.count(a)) dup[a]++;
        else dup[a] = 1;
    }

    ll ans2 = 0;
    for (auto d: dup) {
        int value = d.second;
        if (value == 1) continue;
        ans2 += 1LL * value * (value - 1) / 2;
    }

    cout << ans1 - ans2 << endl;

}
