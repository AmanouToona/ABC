#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

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
    int N, K, Q;
    cin >> N >> K >> Q;

    vector<int> A(K), L(Q);
    for (int i = 0; i < K; i++) cin >> A[i];
    for (int i = 0; i < Q; i++) cin >> L[i];

    for (int sL : L) {
        int num = sL - 1;
        if (A[num] == N) continue;
        if (num == A.size() - 1) {
            A[num]++;
            continue;
        }
        if (A[num] + 1 == A[num + 1]) continue;
        A[num]++;
    }

    for (int i = 0; i < K; i++) {
        if (i != 0) cout << " ";

        cout << A[i];
    }
    cout << endl;
}