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
    string S;
    cin >> S;

    int K; 
    cin >> K;

    int count = 0;
    int ans = 0;
    int r = 0;
    for (int l = 0; l < S.size(); l++) {
        while (r < S.size() && (count < K || S[r] == 'X')) {
            if (S[r] == '.') count++;
            r++;
        }

        ans = max(ans, r - l);

        if (S[l] == '.') count--;

    }

    cout << ans << endl;
}
