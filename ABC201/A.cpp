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
    vector<int> A(3);
    for (int i = 0; i < 3; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    if (A[1] - A[0] == A[2] - A[1]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}