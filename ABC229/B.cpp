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
    string A, B;
    cin >> A >> B;

    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    int digit = min(A.length(), B.length());
    for (int i = 0; i < digit; i++) {
        int a = A[i] - '0';
        int b = B[i] - '0';

        if (a + b > 9) {
            cout << "Hard" << endl;
            return 0;
        }
    }

    cout << "Easy" << endl;
}