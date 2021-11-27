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
    vector<vector<char>> g(2, vector<char>(2));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> g[i][j];
        }
    }

    vector<int> di = {0, -1, 0, 1}, dj = {1, 0, -1, 0};

    bool yes = true;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            bool ok = false;
            if (g[i][j] == '.') continue;
            for (int k = 0; k < 4; k++) {
                int vi = i + di[k];
                int vj = j + dj[k];
                if (vi < 0 || vi > 1) continue;
                if (vj < 0 || vj > 1) continue;
                if (g[vi][vj] == '#') ok = true;
            }
            if (!ok) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;

}