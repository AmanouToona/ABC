#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

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
    int N;
    cin >> N;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<vector<ll>>> ans(N,
                                   vector<vector<ll>>(N, {10100100100100, 0}));

    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;

        for (int j = 0; j < N; j++) {
            if (S[j] == 'N') continue;
            ans[i][j] = {1, A[i] + A[j]};
        };
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ll cost = ans[i][k][0] + ans[k][j][0];
                ll gain = ans[i][k][1] + ans[k][j][1] - A[k];

                if (cost > ans[i][j][0]) continue;

                if (cost < ans[i][j][0]) {
                    ans[i][j] = {cost, gain};
                } else {
                    ans[i][j][1] = max<ll>(ans[i][j][1], gain);
                }
            }
        }
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        ll cost = ans[u][v][0];
        ll gain = ans[u][v][1];

        if (cost > 400) {
            cout << "Impossible" << endl;
            continue;
        }

        cout << cost << " " << gain << endl;
    }
}