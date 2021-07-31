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

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<ll> tot;
    tot.push_back(0);

    for (int i = 1; i <= Q; i++) {
        int p, x;

        cin >> p;

        if (p == 1) {
            cin >> x;
            q.push(make_pair(x - tot.back(), i));
            tot.push_back(tot.back());
        } else if (p == 2) {
            cin >> x;
            tot.push_back(tot.back() + x);
        } else {
            auto [ans, count] = q.top();
            q.pop();
            tot.push_back(tot.back());
            cout << tot.back() + ans << endl;
        }
    }
}

