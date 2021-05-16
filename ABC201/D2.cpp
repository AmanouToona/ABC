#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int point (int h, int w, vector<string> &A) {
    if (A[h][w] == '+') return 1;
    else return -1; 
}

int dfs (int h, int w, vector<string> &A, vector<vector<int>> &P) {

    int H = A.size();
    int W = A[0].size();

    if (h == H - 1 && w == W - 1) return 0;
    if (P[h][w] != INT_MAX) return P[h][w];

    bool takahashi;  // 高橋君が駒を移動させる順番のマスか？
    if ((h + w) % 2 == 0) takahashi = true;
    else takahashi = false;

    if (takahashi) {
        int score = - INT_MAX;
        if (h + 1 < H) {
            score = point(h + 1, w, A) + dfs(h + 1, w, A, P);
        }
        if (w + 1 < W) {
            score = max(score, point(h, w + 1, A) + dfs(h, w + 1, A, P));
        }
        P[h][w] = score;
    } else {
        int score = INT_MAX;
        if (h + 1 < H) {
            score = - point(h + 1, w, A) + dfs(h + 1, w, A, P);
        }
        if (w + 1 < W) {
            score = min(score, - point(h, w + 1, A) + dfs(h, w + 1, A, P));
        }
        P[h][w] = score;
    }

    return P[h][w];
}


int main() {
    int H, W;
    cin >> H >> W;

    vector<string> A(H);
    for (int i = 0; i < H; i++) {
        cin >> A[i];
    }

    vector<vector<int>> P(H, vector<int>(W, INT_MAX));
    int score = dfs(0, 0, A, P);
    if (score > 0) {
        cout << "Takahashi" << endl;
    } else if (score == 0) {
        cout << "Draw" << endl;
    } else {
        cout << "Aoki" << endl;
    }

    return 0;
}