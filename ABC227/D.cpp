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


bool judge(ll ans, ll K ,vector<ll> &A) {
    vector<ll> q();

    ll res = 0;
    ll count = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] >= ans) {
            count++;
            continue;
        } else {
            res += A[i];
            if (res >= ans) {
                count++;
                res -= ans;
            }
        }
    }

    return count >= K;
}


int main() {
    ll N, K;
    cin >> N >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end(), greater<ll>());

    ll left = 0, right = 1000000000000;
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        if (judge(mid, K, A)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << left << endl;

}
