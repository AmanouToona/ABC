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

void eratosthenes(vector<ll>& prime, int N) {
    vector<int> isPrime(N + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 0; i < N; i++) {
        if (!isPrime[i]) continue;

        prime.push_back(i);

        for (int j = i * 2; j <= N; j += i) {
            isPrime[j] = false;
        }
    }
}

int const INF = INT_MAX;

int main() {
    ll N;
    cin >> N;

    vector<ll> prime;
    eratosthenes(prime, 1e6);

    int count = 0;
    for (int i = 0; i < prime.size(); i++) {
        int l = i + 1;
        int r = prime.size();
        ll q3 = N / prime[i];

        if (prime[l] * prime[l] * prime[l] > q3) break;

        while (r - l > 1) {
            int mid = (l + r) / 2;

            if (prime[mid] * prime[mid] * prime[mid] > q3) {
                r = mid;
            } else {
                l = mid;
            }
        }
        count += (l - i);
    }
    cout << count << endl;
}
