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
    vector<string> S(4);
    for (int i = 0; i < 4; i++) {
        cin >> S[i];
    }

    int h=0, twob=0, threeb=0, hr=0;

    for (string s: S) {
        if (s == "H") h++;
        else if (s == "2B") twob++;
        else if (s == "3B") threeb++;
        else hr++;
    }

    if (h == 1 && twob==1 && threeb == 1 && hr == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}