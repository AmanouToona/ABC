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
string inf = "Infinity";

bool colinear(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    int x1 = b.first - a.first;
    int x2 = c.first - a.first;
    int y1 = b.second - a.second;
    int y2 = c.second - a.second;

    return x1 * y2 - x2 * y1 == 0;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> P(N);
    for (int n = 0; n < N; n++) {
        int X, Y;
        cin >> X >> Y;
        P[n] = make_pair(X, Y);
    }

    if (K == 1) {
        cout << inf << endl;
        return 0;
    }

    map<int, int> m;
    vector<vector<bool>> counted(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (!counted[i][j]) {
                int count = 2;
                counted[i][j] = true;

                vector<int> l;
                for (int k = j + 1; k < N; k++) {
                    if (colinear(P[i], P[j], P[k]) && !counted[j][k]) {
                        counted[j][k] = true;
                        counted[i][k] = true;
                        count++;
                        l.push_back(k);
                    }
                }
                for (int ii = 0; ii < l.size(); ii++) {
                    for (int jj = ii + 1; jj < l.size(); jj++) {
                        counted[ii][jj] = true;
                    }
                }
                m[count]++;
            }
        }
    }

    int ans = 0;
    for (auto [k, v] : m) {
        if (k >= K) ans += v;
    }
    cout << ans << endl;
}