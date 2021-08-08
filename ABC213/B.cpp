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

    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A[i] = make_pair(a, i);
    }

    sort(A.begin(), A.end());

    auto [_, ans] = A[N - 2];

    cout << ans + 1 << endl;
}
