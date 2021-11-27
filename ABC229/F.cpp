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

ll dist(vector<int> &B, int x, int y) {
    if (x > y) {
        swap(x, y);
    }

    ll dis_l = 0;
    if (x > 0) {
        dis_l = B[x - 1];
    }

    ll res = B[y - 1] - dis_l;

    res = min<ll>(res, B[B.size() - 1] - B[y - 1] + dis_l);

    return res;
};


int main() {
    int N;
    cin >> N;

    vector<ll> A(N), B(N);
    ll big = 0;
    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] > big) {
            x = 0;
            y = i + 1;
            big = A[i];
        }
    }

    for (int i = 0; i < N; i++) {
        cin >> B[i];
        if (B[i] > big) {
            x = i + 1;
            y = x + 1;
            big = B[i];
        }
    }

    for (int i = 0; i < N - 1; i++) {
        B[i + 1] += B[i];
    }

    ll cost = 0;
    for (int i = 0; i < N; i++) {
        ll dis0 = 
    }



}