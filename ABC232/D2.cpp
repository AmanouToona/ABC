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

    vector<string> C(H);
    for (int h = 0; h < H; h++) {
        cin >> C[h];
    }

    vector<vector<int>> ans(H , vector<int>(W, 0));
    ans[0][0] = 1;

    int final_ans = 1;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (C[h][w] == '#') continue;
            if (h >= 1 && ans[h - 1][w] != 0) {
                ans[h][w] = max(ans[h][w], ans[h - 1][w] + 1);
            }
            if (w >= 1 && ans[h][w - 1] != 0) {
                ans[h][w] = max(ans[h][w], ans[h][w - 1] + 1);
            }

            final_ans = max(final_ans, ans[h][w]);
        }
    }

    cout << final_ans << endl;
}
