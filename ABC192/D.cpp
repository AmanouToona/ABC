#include <bits/stdc++.h>
using namespace std;
using ll = long long;


bool check(ll n, string X, ll M) {
    ll ans = 0;
    for (ll i = 0; i < X.size(); i++) {
        if (M < pow(n, X.size() - 1 - i) * ll(X[i] - '0')) return false;
        ans += ll(X[i] - '0') * pow(n, X.size() - 1 - i);
        if (ans > M) {
            return false;
        }
    }
    return true;
}


int main() {
    string X;
    ll M;

    cin >> X >> M;

    int max_num = 0;
    for (auto x: X) {
        max_num = max(max_num, x - '0');
    }

    if (X.size() == 1) {
        if (X[0] - '0' <= M ) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }

    ll left = max_num + 1, right = M + 1;
    if (check(left, X, M) == false) {
        cout << 0 << endl;
        return 0;
    }

    while (right - left > 1) {
        ll mid = (left + right) / 2;
        if (check(mid, X, M)) left = mid;
        else right = mid;
    }

    ll ans = left;  // int にして時間とかした
    ans = ans - max_num;
    cout << ans << endl;
    return 0;

}