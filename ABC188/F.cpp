#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll x;
map<ll, ll> memo;

ll f(ll y) {
    if (y == x) {
        return 0;
    }

    if (y == 1) {
        memo[y] = abs(x - y);
        return abs(x - y);
    }

    if (memo.find(y) != memo.end()) {return memo[y];}
    if (y % 2 == 0) {
        memo[y] = min(f(y / 2) + 1, abs(x - y));
        return min<ll>(f(y / 2) + 1, abs(x - y));
    }
    else {
        memo[y] = min(f(y + 1), f(y - 1)) + 1;
        return min(f(y + 1), f(y - 1)) + 1;
    }
}


int main() {
    ll y;
    cin >> x >> y;

    cout << f(y) << endl;
    
}
