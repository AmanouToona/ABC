#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < N; i++) cin >> C[i];
    for (int i = 0; i < N; i++) C[i]--;

    vector<int> count(N, 0);
    for (auto c: C) {
        count[B[c]]++;
    }

    ll ans = 0;
    for (auto a: A) {
        ans += count[a];
    }

    cout << ans << endl;

}