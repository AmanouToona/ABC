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

    int ans = 1;
    int ans_sum = 0;
    vector<int> ans_vec;
    while (1) {
        ans_sum += ans;
        ans_vec.push_back(ans);
        ans_vec.push_back(ans_sum);
        ans *= 2;
        if (ans > W) break;
    }

    vector<int> ans_final;
    for (int i = 0; i < ans_vec.size(); i++) {
        if (ans_vec[i] > 1e6) break;
        ans_final.push_back(ans_vec[i]);
    }

    cout << ans_final.size() << endl;
    for (int i = 0; i < ans_final.size(); i++) {
        if (ans_final[i] > 1e6) break;
        if (i != 0) {
            cout << " ";
        }
        cout << ans_final[i];
    }
    cout << endl;
}
