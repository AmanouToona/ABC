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
    int H, W;
    cin >> H >> W;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> A[i][j];
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int i2 = i + 1; i2 < H; i2++) {
                for (int j2 = j + 1; j2 < W; j2++) {
                    if (A[i][j] + A[i2][j2] > A[i2][j] + A[i][j2]) {
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "Yes" << endl;

    return 0;

}