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
    ll a_sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        a_sum += A[i];
    }

    ll ans = 0;
    for (int i = 0; i < N - 1; i++) {
        a_sum -= A[i];
        ans -= 2 *A[i] * a_sum;
    }

    for (int i = 0; i < N; i++) {
        ans += (N - 1) * 1LL * A[i] * A[i];
        // cout << typeid(ans).name() << endl;
    }

    cout << ans << endl;
    return 0;

}

