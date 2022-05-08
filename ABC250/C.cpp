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
    int N, Q;
    cin >> N >> Q;

    vector<int> x;
    vector<int> pos;

    for (int i = 0; i < N; i++) {
        x.push_back(i);
        pos.push_back(i);
    }

    for (int i = 0; i < Q; i++) {
        int xq;
        cin >> xq;
        xq--;

        int pos1 = pos[xq];
        int pos2;
        if (pos1 == N - 1)
            pos2 = pos1 - 1;
        else
            pos2 = pos1 + 1;

        int x1 = x[pos1];
        int x2 = x[pos2];

        x[pos1] = x2;
        x[pos2] = x1;

        pos[x1] = pos2;
        pos[x2] = pos1;
    }

    for (int i = 0; i < N; i++) {
        if (i != 0) cout << " ";
        cout << x[i] + 1;
    }
    cout << endl;
}
