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
    double A, B;
    cin >> A >> B;

    double ans_a = A / sqrt(A * A + B * B);
    double ans_b = B / sqrt(A * A + B * B);
    cout << fixed << setprecision(10) << ans_a << " " << ans_b << endl;
}