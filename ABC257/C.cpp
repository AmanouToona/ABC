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
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> W(N);
    for (int i = 0; i < N; i++) cin >> W[i];

    vector<pair<int, char>> p;
    for (int i = 0; i < N; i++) {
        p.push_back(make_pair(W[i], S[i]));
    }

    sort(p.begin(), p.end());

    int ans_temp = 0;
    for (char s : S)
        if (s == '1') ans_temp++;
    int ans = ans_temp;

    int l = 0;
    while (l < N) {
        if (p[l].second == '0')
            ans_temp++;
        else
            ans_temp--;
        while (l + 1 < N && p[l].first == p[l + 1].first) {
            if (p[l + 1].second == '0')
                ans_temp++;
            else
                ans_temp--;
            l++;
        }

        ans = max(ans, ans_temp);
        l++;
    }

    cout << ans << endl;
}
