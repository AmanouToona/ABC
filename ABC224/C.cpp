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

    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                ll ax = X[j] - X[i];
                ll ay = Y[j] - Y[i];
                ll bx = X[k] - X[i];
                ll by = Y[k] - Y[i];

                ll dot = ax * bx + ay * by;
                if (dot * dot == (ax * ax + ay * ay) * (bx * bx + by * by)) continue;
                ans ++;
            }
        }
    }

    cout << ans << endl;

}
