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

    map<vector<int>, int> m;
    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;

        vector<int> a(L);
        for (int l = 0; l < L; l++) cin >> a[l];

        m[a] = m.size();
    }

    cout << m.size() << endl;

}