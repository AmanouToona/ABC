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

void printPath1_aux(int begin, int end, vector<vector<int>> &via,
                    vector<vector<bool>> &e2) {
    if (via[begin][end] == begin) {
        if (begin != end) {
            e2[begin][end] = true;
            e2[end][begin] = true;
        };
        return;
    }

    printPath1_aux(begin, via[begin][end], via, e2);
    printPath1_aux(via[begin][end], end, via, e2);
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> dp(N, vector<int>(N, INF));
    vector<vector<bool>> e(N, vector<bool>(N, false));
    vector<int> u(N, -1);

    for (int i = 0; i < N; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        A--;
        B--;
        dp[A][B] = C;
        dp[B][A] = C;
        e[A][B] = true;
        e[B][A] = true;
    }

    vector<vector<int>> via(N, vector<int>(N, -1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) via[i][j] = i;
    }

    for (int k = 0; k < N; k++) {
        for (int l = 0; l < N; l++) {
            for (int m = 0; m < N; m++) {
                if (dp[l][k] + dp[k][m] < dp[l][m]) {
                    dp[l][m] = dp[l][k] + dp[k][m];
                    via[l][m] = k;
                }
            }
        }
    }

    vector<vector<bool>> e2(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printPath1_aux(i, j, via, e2);
        }
    }
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (e2[i][j] != e[i][j]) count++;
        }
    }
    cout << count / 2 << endl;
}