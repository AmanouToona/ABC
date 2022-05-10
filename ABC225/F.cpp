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

    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    sort(S.begin(), S.end());

    vector<string> O;
    for (int i = 0; i < K; i++) {
        O.push_back(S[i]);
    }

    for (string o: O){
        cout << o;
    }
    cout << endl;

}