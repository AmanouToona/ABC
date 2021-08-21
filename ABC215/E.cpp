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
int const mod = 998244353;

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    vector<int> contest;
    for (char s: S) {
        if (s == 'A') {contest.push_back(0);}
        else if (s == 'B') {contest.push_back(1);}
        else if (s == 'C') {contest.push_back(2);}
        else if (s == 'D') {contest.push_back(3);}
        else if (s == 'E') {contest.push_back(4);}
        else if (s == 'F') {contest.push_back(5);}
        else if (s == 'G') {contest.push_back(6);}
        else if (s == 'H') {contest.push_back(7);}
        else if (s == 'I') {contest.push_back(8);}
        else if (s == 'J') {contest.push_back(9);}
    }

    vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(10, vector<ll>(10, 0)));
    dp[0][contest[0]][contest[0]] = 1;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                // contest i を選ぶ場合
                dp[i][contest[j]][k]
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < 10; j++) {
        for (int k = 0; k < 10; k++) {
            ans += dp[N - 1][j][k];
            ans %= mod;
        }
    }
    cout << ans << endl;
}