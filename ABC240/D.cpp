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

    vector<pair<int, int>> k;
    int tot = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        tot++;

        k.push_back(make_pair(a, 1));

        while (true) {
            if (k.size() == 0) break;
            if (k.size() == 1) {
                if (k[0].first <= k[0].second) {
                    k[0].second -= k[0].first;
                    tot -= k[0].first;
                }
                break;
            }
            if (k[k.size() - 1].first <= k[k.size() - 1].second) {
                k[k.size() - 1].second -= k[k.size() - 1].first;
                tot -= k[k.size() - 1].first;
                if (k[k.size() - 1].second == 0) k.pop_back();
            }

            if (k[k.size() - 1].first != k[k.size() - 2].first) break;
            k[k.size() - 2].second += k[k.size() - 1].second;
            k.pop_back();
        }
        cout << tot << endl;
    }
}
