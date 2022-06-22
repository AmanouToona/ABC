#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;

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
    vector<int> h(3), w(3);
    for (int i = 0; i < 3; i++) cin >> h[i];
    for (int i = 0; i < 3; i++) cin >> w[i];

    // |a|b|c|
    // |d|e|f|
    // |g|h|i|
    int cnt = 0;
    for (int a = 1; a <= w[0]; a++) {
        for (int b = 1; a + b <= w[0]; b++) {
            int c = w[0] - a - b;
            if (c < 1) continue;

            for (int d = 1; d <= w[1]; d++) {
                for (int e = 1; e <= w[1]; e++) {
                    int f = w[1] - d - e;
                    if (f < 1) continue;

                    int g = h[0] - a - d;
                    int hh = h[1] - b - e;

                    if (g < 1 || hh < 1) continue;

                    if (w[2] - g - hh == h[2] - c - f && (w[2] - g - hh > 0))
                        cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
}
