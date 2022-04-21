#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> is(N + 1);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        is[a].push_back(i);
    }

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int L, R, X;
        cin >> L >> R >> X;
        L--;
        R--;

        auto f = [&](vector<int>& is, int r) {
            return upper_bound(is.begin(), is.end(), r) - is.begin();
        };

        cout << f(is[X], R) - f(is[X], L - 1) << endl;
    }
}
