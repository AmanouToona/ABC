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

    vector<int> A(N), B(N);
    set<int> s;
    map<int, ll> m;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        s.insert(A[i]);
        s.insert(A[i] + B[i] - 1);
        s.insert(A[i] + B[i]);

    }

    vector<int> vec(s.begin(), s.end());
    sort(vec.begin(), vec.end());
    for (int v: vec) {
        m[v] = m.size();
    }

    map<ll, int> m_inv;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        m_inv[iter -> second] = iter -> first;
    }

    vector<int> dp(m.size() + 1, 0);
    for (int i = 0; i < N; i++) {
        dp[m[A[i]]]++;
        dp[m[A[i] + B[i] - 1] + 1]--;
    }

    for (int i = 0; i < dp.size(); i++) {
        dp[i + 1] += dp[i];
    }

    vector<int> ans(N, 0);
    for (int i = 0; i < dp.size() - 1; i++) {
        if (dp[i] == 0) continue;
        ans[dp[i] - 1] += int(m_inv[i + 1] - m_inv[i]);
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1) cout << " ";
    }
    cout << endl;

}
