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

    int count=3;
    map<char, int> m;
    for (char s: S) {
        if (m.count(s) != 0) count--;
        else m[s] ++;
    }

    if (count==3) {
        cout << 6 << endl;
    } else if (count == 2) {
        cout << 3 << endl;
    } else {
        cout << 1 << endl;
    }

}