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
int H, W, A, B;

bool fp[16][16];
int dfs(int h, int w, int a, int b) {
    if (a < 0 || b < 0) return 0;
    if (w == W) w = 0, h++;
    if (h == H) return 1;
    if (fp[h][w]) return dfs(h, w + 1, a, b);

    fp[h][w] = true;
    int res = 0;
    // B
    res += dfs(h, w + 1, a, b - 1);
    // A 横
    if (w + 1 < W && !fp[h][w + 1]) {
        fp[h][w + 1] = true;
        res += dfs(h, w + 2, a - 1, b);
        fp[h][w + 1] = false;
    }
    // A 縦
    if (h + 1 < H && !fp[h + 1][w]) {
        fp[h + 1][w] = true;
        res += dfs(h, w + 1, a - 1, b);
        fp[h + 1][w] = false;
    }

    fp[h][w] = false;
    return res;
}


int main() {
    cin >> H >> W >> A >> B;
    int ans = dfs(0, 0, A, B);
    cout << ans << endl;    
}
