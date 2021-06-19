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

    int price = floor(N * 1.08);

    if (price < 206) {
        cout << "Yay!" << endl;
    } else if (price == 206) {
        cout << "so-so" << endl;
    } else {
        cout << ":(" << endl;
    }
}