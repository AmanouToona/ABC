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

    vector<vector<int>> pos(10, vector<int>(N));
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < 10; j++) {
            pos[s[j] - '0'][i] = j;
        }
    }

    int ans = 1e6;
    for (int i = 0; i < 10; i++) {
        vector<int> i_pos(10);
        for (int p : pos[i]) {
            i_pos[p]++;
        }

        int i_ans = 0;
        for (int j = 0; j < 10; j++) {
            i_ans = max(i_ans, (i_pos[j] - 1) * 10 + j);
        }
        ans = min(ans, i_ans);
    }

    cout << ans << endl;
}
