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
    string s;
    int k;
    cin >> s >> k;

    sort(s.begin(), s.end());
    int count = 1;

    while (count < k && next_permutation(s.begin(), s.end())) {
        count ++;
    }

    cout << s << endl;

}
