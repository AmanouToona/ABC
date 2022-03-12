#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;

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
    ll N, X;
    cin >> N >> X;

    string S;
    cin >> S;

    string S2;
    for (auto s : S) {
        if (s == 'U' && S2.size() > 0 && S2[S2.size() - 1] != 'U') {
            S2.pop_back();
        } else {
            S2.push_back(s);
        }
    }

    for (auto s : S2) {
        if (s == 'U')
            X /= 2;
        else if (s == 'L')
            X = X * 2;
        else
            X = X * 2 + 1;
    }

    cout << X << endl;
}
