#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, X;
    cin >> N >> X;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        if (A[i] != X) {
            cout << A[i] << " ";
        }
    }
    cout << endl;

}