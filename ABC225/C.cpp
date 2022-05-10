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
    int N, M;
    cin >> N >> M;

    vector<vector<ll>> B(N, vector<ll>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> B[i][j];
    }

    bool ans = false;
    for (int j = 1; j <= 7; j++) {

        if (B[0][0] - j < 0) continue;
        if ((B[0][0] - j) % 7 != 0) continue;
 
        int i = (B[0][0] - j) / 7 + 1;

        bool in_break = false;
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                if (j + m > 7) {
                    in_break = true;
                    break;
                }
                if (B[n][m] == (i + n - 1) * 7 + j + m) continue;
                in_break = true;
            }
            if (in_break) break;
            if (n == N - 1) ans = true;
        }
    }

    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}
