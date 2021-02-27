#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int const INF = INT_MAX;

int main() {
    int N;
    cin >> N;

    int ans = INF;
    for (int i = 0; i < N; i++) {
        int A, P, X;
        cin >> A >> P >> X;
        if (X - A <= 0) continue;

        ans = min(ans, P);
    }

    if (ans == INF) {cout << -1<< endl; return 0;}
    cout << ans << endl;
    return 0;

}