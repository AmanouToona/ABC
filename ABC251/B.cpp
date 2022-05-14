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

int const INF = INT_MAX;

int main() {
    int N, W;
    cin >> N >> W;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    A.push_back(0);
    A.push_back(0);

    set<int> ans;
    // for (int i = 0; i < N; i++) {
    //     ans.insert(A[i]);
    // }

    sort(A.begin(), A.end());

    for (int i = 0; i < A.size(); i++) {
        for (int j = i + 1; j < A.size(); j++) {
            for (int k = j + 1; k < A.size(); k++) {
                if (A[i] + A[j] + A[k] > W) break;
                ans.insert(A[i] + A[j] + A[k]);
            }
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = i + 1; j < N; j++) {
    //         ans.insert(A[i] + A[j]);
    //     }
    // }

    // for (int i = 0; i < N; i++) {
    //     ans.insert(A[i]);
    // }

    // vector<int> ans2(ans.begin(), ans.end());

    // sort(ans2.begin(), ans2.end());

    // int cnt = 0;
    // for (int a : ans2) {
    //     if (a > W) break;
    //     cnt++;
    // }
    cout << ans.size() << endl;
}