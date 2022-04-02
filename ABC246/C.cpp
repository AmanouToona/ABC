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
    int N, K, X;
    cin >> N >> K >> X;

    priority_queue<int> A;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push(a);
    }

    while (K > 0) {
        int a = A.top();
        A.pop();
        int k = a / X;
        if (k > K) {
            a -= K * X;
            K = 0;
            A.push(a);
            continue;
        }

        if (k > 0) {
            a -= k * X;
            K -= k;
            A.push(a);
            continue;
        }

        A.push(a);
        break;
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int a = A.top();
        A.pop();
        if (i < K) continue;
        ans += a;
    }
    cout << ans << endl;
}
