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

void solve (int a, int m, vector<bool>& ans) {
    if (a <=m && a != 1) {
        ans[a] = false;
    }
    int i = 2;
    while (i * i < a && i <=m) {
        if (a % i == 0) {
            ans[i] = false;
            if (a / i <= m) ans[a / i] = false;
        }
        i++;
    }
}


void sieve(int m, vector<bool> &isprime) {
    isprime[0] = false;
    isprime[1] = false;
    for (int i = 2; i * i <= m; i++) {
        if (isprime[i]) {
            for (int j = 2; j * i <= m; j++) {
                isprime[i * j] = false;
            }
        }
    }
}



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    if (M == 1) {
        cout << 1 << endl;
        cout << 1 << endl;
        return 0;
    }

    vector<bool> ans(M + 1, true);
    ans[0] = false;
    for (int a: A) {
        solve(a, M, ans);
    }

    vector<bool> isprime(M + 1, true);
    sieve(M, isprime);

    for (int i = 0; i <=M; i++) {
        if (! isprime[i]) continue;
        if (ans[i]) continue;

        for (int j = i; j <= M; j+=i) {
            ans[j] = false;
        }
    }

    vector<int> res;
    for (int i = 1; i <= M; i++) {
        if (ans[i]) res.push_back(i);
    }

    cout << res.size() << endl;
    for (int i : res) {
        cout << i << endl;
    }
    cout << endl;


}
