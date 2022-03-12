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
    int N;
    cin >> N;

    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

    string S;
    cin >> S;

    map<int, vector<int>> m;
    for (int i = 0; i < N; i++) {
        m[Y[i]].push_back(i);
    }

    bool collision = false;

    for (auto [y, V] : m) {
        sort(V.begin(), V.end(),
             [&](int i, int j) -> bool { return X[i] < X[j]; });

        bool is_right = false;
        for (int v : V) {
            if (S[v] == 'R') {
                is_right = true;
                continue;
            }
            if (S[v] == 'L' && is_right) {
                collision = true;
            }
        }
    }

    if (collision) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    /*
3
2 3
4 1
1 1
RLR

    */
}
