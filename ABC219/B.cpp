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
    vector<string> S(3);
    cin >> S[0] >> S[1] >> S[2];

    string T;
    cin >> T;

    for (char t: T) {
        int i = t - '0';
        i--;
        cout << S[i];
    }

    cout << endl;

}
