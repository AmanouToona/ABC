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
    int N, D;
    cin >> N >> D;

    vector<int> L(N), R(N);
    for (int i = 0; i < N; i++) cin >> L[i] >> R[i];

    vector<int> ids(N);
    for (int i = 0; i < N; i++) ids[i] = i;

    sort(ids.begin(), ids.end(), [&](int i, int j) {
        return R[i] < R[j];
    });

    int ans = 1;
    int right = R[ids[0]] + D - 1;
    for (int i = 0; i < N; i++) {
        if (L[ids[i]] <= right) continue;
        ans++;
        right = R[ids[i]] + D - 1;
    }

    cout << ans << endl;

}
