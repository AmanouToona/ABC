#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll ans = LLONG_MAX;
    for (int i = 0; i < (1 << (N - 1)); i++) {
        vector<ll> B;
        ll temp = 0;
        for (int j = 0; j < (N - 1); j++) {
            if ((i >> j) & 1) {
                B.push_back(temp | A[j]);
                temp = 0;
            } else {
                temp = temp | A[j];
            }
        }
        B.push_back(temp | A[N - 1]);
        
        temp = 0;
        for (auto b: B) {
            temp = temp ^ b;
        }
        ans = min<ll>(ans, temp);
    }

    cout << ans << endl;

}