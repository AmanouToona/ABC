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

vector<int> compress(vector<int> A) {
    vector<int> A2 = A;

    sort(A2.begin(), A2.end());
    map<int, int> mp;
    for (int a: A2) {
        if (mp.count(a) == 0) mp[a] = mp.size();
    }

    for (int i = 0; i < A.size(); i++) {
        A[i] = mp[A[i]];
    }

    return A;
}


int main() {
    int H, W, N;
    cin >> H >> W >> N;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    A = compress(A);
    B = compress(B);

    for (int i = 0; i < N; i++) {
        cout << A[i] + 1<< " " << B[i] + 1 << endl;
    }

}
