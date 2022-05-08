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
    int N, A, B;
    cin >> N >> A >> B;

    string s1 = "";
    string s2 = "";

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < B; j++) {
            if (i % 2 == 0) {
                s1.push_back('.');
                s2.push_back('#');
            } else {
                s1.push_back('#');
                s2.push_back('.');
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < A; j++) {
            if (i % 2 == 0) {
                cout << s1 << endl;
            } else {
                cout << s2 << endl;
            }
        }
    }
}