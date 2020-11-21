#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int dp[2001][2001];
int dpx[2001][2001];
int dpy[2001][2001];
int dpxy[2001][2001];

int main() {


    dp[0][0] = 1;
    dpx[0][0] = 1;
    dpy[0][0] = 1;
    dpxy[0][0] = 1;

    int H, W;
    cin >> H >> W;

    vector<string> board(H);
    for (int h = 0; h < H; h++) {
        cin >> board[h];
    }

    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (h == 0 && w == 0) continue;
            if (board[h][w] == '#') continue; 

            if (w >= 1) dpx[h][w] += dpx[h][w - 1] % mod;
            if (h >= 1) dpy[h][w] += dpy[h - 1][w] % mod;
            if (w >= 1 && h >= 1) dpxy[h][w] += dpxy[h - 1][w - 1] % mod;

            dp[h][w] += dpx[h][w];
            dp[h][w] %= mod;

            dp[h][w] += dpy[h][w];
            dp[h][w] %= mod;

            dp[h][w] += dpxy[h][w];
            dp[h][w] %= mod;
            
            dpx[h][w] += dp[h][w];
            dpy[h][w] += dp[h][w];
            dpxy[h][w] += dp[h][w];
        }
    }

    cout << dp[H - 1][W - 1] % mod << endl;
}
