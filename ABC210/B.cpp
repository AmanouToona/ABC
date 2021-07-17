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

    string S;
    cin >> S;

    int counter = 0;
    for (char s: S) {
        if (s == '1') {
            break;
        } else {
            counter ++;
        }
    }

    if (counter % 2 == 0) {
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }
}