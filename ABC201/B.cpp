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

    vector<string> S(N);
    vector<int> T(N);

    for (int i = 0; i < N; i++) {
        cin >> S[i] >> T[i];
    }

    vector<pair<int, string>> mount;
    for (int i = 0; i < N; i++) {
        mount.push_back(make_pair(T[i], S[i]));
    }

    sort(mount.begin(), mount.end());

    cout << mount[N - 2].second << endl;

}