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
    vector<int> X(N), C(N);
    for (int i = 0; i < N; i++) cin >> X[i];
    for (int i = 0; i < N; i++) cin >> C[i];
}