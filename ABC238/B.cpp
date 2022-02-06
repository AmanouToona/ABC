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

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 0; i < A.size() - 1; i++) {
        A[i + 1] += A[i];
        A[i + 1] %= 360;
    }

    A.push_back(0);
    A.push_back(360);
    sort(A.begin(), A.end());

    int ans = 0;
    for (int i = 0; i < A.size() - 1 ; i++) {
        ans = max(A[i + 1] - A[i], ans);
    }

    cout << ans << endl;

}
