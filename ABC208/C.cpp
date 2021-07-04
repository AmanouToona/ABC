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
    ll N, K;
    cin >> N >> K;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        B[i] = A[i];
    }

    sort(A.begin(), A.end());

    ll base = K / N;
    K -= base * N;

    for (int b: B) {
        if (b < A[K]) {
            cout << base + 1 << endl;
        } else {
            cout << base << endl;
        }
    }


}
