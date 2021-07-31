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
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // a が小さいとき
    int i = 0;
    int ans = INF;
    for (int a: A) {
        while(B[i] < a && i < M - 1) {
            i++;
        }

        ans = min(ans, abs(B[i] - a));
    }
    // a が大きい時
    i = 0;
    for (int b: B) {
        while(A[i] < b && i < N - 1) i++;

        ans = min(ans, abs(A[i] - b));
    }

    cout << ans << endl;
    
}
