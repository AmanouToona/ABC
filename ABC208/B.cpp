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
    int P;
    cin >> P;

    vector<int> coin;
    int _price = 1;
    for (int i = 1; i <= 10; i++) {
        _price *= i;
        coin.push_back(_price);
    }

    sort(coin.rbegin(), coin.rend());

    int ans = 0;
    int coin_i = 0;
    while (P > 0) {
        if (P < coin[coin_i]) {
            coin_i ++;
            continue;
        }

        ans++;
        P -= coin[coin_i];
    }

    cout << ans << endl;


}