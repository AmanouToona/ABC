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

    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    vector<int> dh = {0, -1, 0, 1};
    vector<int> dw = {-1, 0, 1, 0};
    deque<pair<int, int>> q;
    vector<vector<int>> ans(H, vector<int>(W, INF));
    ans[0][0] = 0;

    q.push_front(make_pair(0, 0));

    while(!q.empty()) {
        auto [uh, uw] = q.front(); 
        q.pop_front();

        for (int i = 0; i < 4; i++) {
            int vh = uh + dh[i];
            int vw = uw + dw[i];

            if (vh < 0 || vh >= H) continue;
            if (vw < 0 || vw >= W) continue;

            int punch = ans[uh][uw];
            if (S[vh][vw] != '#') {
                if (punch >= ans[vh][vw]) continue;
                ans[vh][vw] = punch;
                q.push_front(make_pair(vh, vw));
                continue;
            }

            punch++;
            for (int ph = -2; ph <= 2; ph++) {
                for (int pw = -2; pw <= 2; pw++) {
                    int vh = uh + ph;
                    int vw = uw + pw;

                    if (abs(ph) + abs(pw) == 4) continue;
                    if (vh < 0 || vh >= H) continue;
                    if (vw < 0 || vw >= W) continue;
                    if (punch >= ans[vh][vw]) continue;

                    ans[vh][vw] = punch;
                    q.push_back(make_pair(vh, vw));
                }
            }

        }
    }

    cout << ans[H - 1][W - 1] << endl;

}