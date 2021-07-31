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
    int Q;
    cin >> Q;

    priority_queue<ll, vector<ll>, greater<ll>> q;

    ll tot = 0;

    for (int i = 0; i < Q; i++) {
        int p, x;

        cin >> p;

        if (p == 1) {
            cin >> x;
            q.push(x - tot);
            continue;
        } else if (p == 2) {
            cin >> x;
            if (q.empty()) continue;
            tot += x;
        } else {
            ll ans = q.top();
            q.pop();
            cout << tot + ans << endl;
        }
    }

}
