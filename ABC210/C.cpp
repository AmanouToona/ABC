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
    int N, K;
    cin >> N >> K;

    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    map<int, int> m;
    for (int i = 0; i < K; i++) {
        m[C[i]] += 1;
    }

    int ans = m.size();

    if (K == N) {
        cout << ans << endl;
        return 0;
    }

    for (int i = K; i < N; i++) {
        m[C[i]] ++;
        m[C[i - K]]--;
        if (m[C[i - K]] == 0) {
            m.erase(C[i - K]);
        }

        int _temp = m.size();
        ans = max(ans, _temp);
    }

    cout << ans << endl;

}
