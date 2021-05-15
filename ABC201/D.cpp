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
    vector<string> A(H);
    for (int i = 0; i < H; i++) {
        cin >> A[i];
    }

    vector<vector<int>> P(H, vector<int>(W, 0));
    if ((H + W)  % 2 == 0) {
        if (A[H - 1][W - 1] == '-') P[H - 1][W - 1]++;
        else P[H - 1][W - 1]--;
    } else {
        if (A[H - 1][W - 1] == '-') P[H - 1][W - 1]--;
        else P[H - 1][W - 1]++;
    }
    if (H == 1 && W == 1) {
        P[0][0] = 0;
    }

    for (int h = H - 1; h >= 0; h--) {
        for (int w = W - 1; w >= 0; w--) {
            if (h == H - 1 && w == W - 1) continue;
            
            bool taka;
            if ((h + w) % 2 == 0) taka = false;
            else taka = true;

            if (h == 0 && w == 0) {
                if (!taka)  {
                    int point = -1 * INT_MAX;
                    if (h + 1 < H) {
                        point = max(point, P[h + 1][w]);
                    } 
                    if (w + 1 < W) {
                        point = max(point, P[h][w + 1]);
                    }
                    P[0][0] = point;
                    break;
                } else {
                    int point = INT_MAX;
                    if (h + 1 < H) {
                        point = min(point, P[h + 1][w]);
                    } 
                    if (w + 1 < W) {
                        point = min(point, P[h][w + 1]);
                    }
                    P[0][0] = point;
                    break;
                }
            }

            if (taka) {
                int point;
                if (A[h][w] == '+') point = 1;
                else point = -1;
                int temp_point = -1 * INT_MAX;
                if (h + 1 < H) {
                    temp_point = max(temp_point, P[h + 1][w]);
                }
                if (w + 1 < W) {
                    temp_point = max(temp_point, P[h][w + 1]);
                }
                P[h][w] = temp_point + point;
            } else {
                int point;
                if (A[h][w] == '+') point = -1;
                else point = 1;
                int temp_point = INT_MAX;
                if (h + 1 < H) {
                    temp_point = min(temp_point, P[h + 1][w]);
                }
                if (w + 1 < W) {
                    temp_point = min(temp_point, P[h][w + 1]);
                }
                P[h][w] = temp_point + point;
            }
        }
    }

    if (P[0][0] > 0) {
        cout << "Takahashi" << endl;
    } else if (P[0][0] == 0) {
        cout << "Draw" << endl;
    } else {
        cout << "Aoki" << endl;
    }

}
