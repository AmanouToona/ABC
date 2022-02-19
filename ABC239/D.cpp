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

vector<int> sieve(int n) {
    vector<bool> isprime(n + 1, true);
    isprime[1] = false;
    isprime[0] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isprime[i]) {
            for (int j = 2; i * j <= n; j++) {
                isprime[i * j] = false;
            }
        }
    }

    vector<int> res;
    for (int i = 0; i < isprime.size(); i++) {
        if (isprime[i]) res.push_back(i);
    }
    return res;
};

int const INF = INT_MAX;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    vector<int> prime = sieve(max(A, B) + max(C, D));

    bool win_t = false;

    for (int i = A; i <= B; i++) {
        bool win_small = true;
        for (int p : prime) {
            int target = p - i;
            if (target > D || target < C) continue;
            win_small = false;
        }
        if (win_small) win_t = true;
    }

    if (win_t) {
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }
}
