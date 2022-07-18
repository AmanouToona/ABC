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
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    set<int> B;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < K; i++) {
        int b;
        cin >> b;
        B.insert(b);
    }

    int max_a = *max_element(A.begin(), A.end());

    for (int i = 0; i < N; i++) {
        if (A[i] != max_a) continue;
        if (B.count(i + 1)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}