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

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<ll>> dp(N, vector<ll>(N, INF));
    for (int i = 0; i < N; i++) dp[i][i] = 0;

    vector<tuple<int, int, int>> e;
    for (int i = 0; i < M; i++) {
        ll A, B, C;
        cin >> A >> B >> C;

        A--;
        B--;
        dp[A][B] = C;
        dp[B][A] = C;
        e.push_back(make_tuple(A, B, C));
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dp[i][j] = min<ll>(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    int unuse = 0;
    for (auto [A, B, C] : e) {
        for (int i = 0; i < N; i++) {
            if (i == A || i == B) continue;
            if (dp[A][i] + dp[i][B] <= C) {
                unuse++;
                break;
            }
        }
    }

    cout << unuse << endl;
}