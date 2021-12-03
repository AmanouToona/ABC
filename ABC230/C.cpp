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

bool is_black(ll N, ll A, ll B, ll x, ll y) {
    // 1
    ll k_left = max(1LL - A, 1LL - B);
    ll k_right = min(N - A, N - B);

    if (x - A == y - B) {
        ll k = x - A;
        if (k >= k_left && k <= k_right) return true;
    }

    k_left = max(1LL - A, B - N);
    k_right = min(N - A, B - 1LL);

    if (x - A == B - y) {
        ll k = x - A;
        if (k >= k_left && k <= k_right) return true;
    }

    return false;
} 


int main() {
    ll N, A, B;
    cin >> N >> A >> B;

    ll P, Q, R, S;
    cin >> P >> Q >> R >> S;

    for (int i = 0; i < Q - P + 1; i++) {
        for (int j = 0; j < S - R + 1; j++) {
            if (is_black(N, A, B, P + i, R + j)) {
                cout << "#";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }

    cout << endl;
    
}
