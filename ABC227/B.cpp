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
    vector<int> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    sort(S.begin(), S.end());

    vector<bool> can(N, false);
    for (int i = 0; i < N; i++ ){
        for (int a = 1; 7 * a <= S[i]; a++) {
            for (int b = 1; 4 * a * b + 3 * a + 3 * b <= S[i]; b++) {
                if (4 * a * b + 3 * a + 3 * b == S[i]) {
                    can[i] = true;
                    break;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (!can[i]) ans++;
    }

    cout << ans << endl;

}