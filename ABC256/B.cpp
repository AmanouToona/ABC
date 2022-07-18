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
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    reverse(A.begin(), A.end());

    int sum_a = 0;
    int left = N;
    for (int i = 0; i < N; i++) {
        sum_a += A[i];
        if (sum_a >= 4) {
            left = i;
            break;
        }
    }
    cout << N - left << endl;
}