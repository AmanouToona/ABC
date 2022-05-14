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
    int W;
    cin >> W;

    vector<int> ans;
    for (int i = 1; i < 101; i++) {
        ans.push_back(101 * i);
        ans.push_back(1 * i);

        if (101 * 101 * i > 1e6) continue;
        ans.push_back(101 * 101 * i);
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;
}
