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
    int N, X;
    cin >> N >> X;

    int tot = 0;
    for (int i = 1; i <= N; i++) {
        int A;
        cin >> A;

        tot += A;
        if (i % 2 == 0) tot -= 1;
    }

    if (tot <= X) cout << "Yes" << endl;
    else cout << "No" << endl;
}