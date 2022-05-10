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
    int N;
    cin >> N;

    vector<vector<int>> t(N, vector<int>());
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        t[a].push_back(b);
        t[b].push_back(a);
    }

    bool star = true;
    if (t[0].size() != N - 1) {
        if (t[0].size() == 0) {
            star = false;
        } else {
            int center = t[0][0];
            if (t[center].size() != N - 1) {
                star = false;
            }
        }
    }

    if (star) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}
