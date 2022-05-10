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

int ans = 0;

void dfs (vector<string> &C, int nh, int nw, int count) {
    if (ans == C.size() + C[0].size()) return;
    if (ans < count) ans = count;

    if (nh + 1 < C.size() && C[nh + 1][nw] != '#') {
        dfs(C, nh + 1, nw, count + 1);
    }
    if (nw + 1 < C[0].size() && C[nh][nw + 1] != '#') {
        dfs(C, nh, nw + 1, count + 1);
    }
}


int main() {
    int H, W;
    cin >> H >> W;

    vector<string> C(H);
    for (int h = 0; h < H; h++) {
        cin >> C[h];
    }

    dfs(C, 0, 0, 1);
    
    cout << ans << endl;

}
