#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    int total = 0;
    for (int i = 0; i < N; i++) {
        int V, P;
        cin >> V >> P;
        total += V * P;

        if (total > X * 100) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}