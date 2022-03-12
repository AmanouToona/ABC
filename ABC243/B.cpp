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
    int N;
    cin >> N;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    int one = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == B[i]) one++;
    }

    map<int, int> m;
    for (int i = 0; i < N; i++) {
        m[A[i]]++;
        m[B[i]]++;
    }

    int two = 0;
    for (auto [i, v] : m) {
        if (v == 2) {
            two++;
        }
    }

    cout << one << endl;
    cout << two - one << endl;
}