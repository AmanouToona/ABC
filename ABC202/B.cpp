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
    string S;
    cin >> S;

    string ans = "";
    for (int i = S.size() - 1; i >= 0; i--) {
        ans.push_back(S[i]);
    }

    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == '6') {
            ans[i] = '9';
        } else if (ans[i] == '9') {
            ans[i] = '6';
        }
    }

    cout << ans << endl;

}