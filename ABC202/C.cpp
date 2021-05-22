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

    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < N; i++) cin >> C[i];
    for (int i = 0; i < N; i++) C[i]--;

    sort(A.begin(), A.end());
    sort(C.begin(), C.end());

    vector<int> BC;
    for (auto c: C) {
        if (c >= N) break;
        BC.push_back(B[c]);
    }
    
    sort(BC.begin(), BC.end());

    ll ans = 0, left = 0, ans_preb = 0;
    for (int i =0; i < A.size(); i++) {
        int a = A[i];
        if (i >= 1 && A[i] == A[i - 1]) {
            ans += ans_preb;
            continue;
        } else {
            ans_preb = 0;
        }

        while(left < N && BC[left] < a) {
            left++;
        }
        if (BC[left] == a) {
            while(left < N && BC[left] == a) {
                left++;
                ans_preb++;
                ans++;
            }
        }
    }

    cout << ans << endl;

}
