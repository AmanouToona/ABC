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
    int N, M;
    cin >> N >> M;

    vector<vector<bool>> T(N, vector<bool>(N, false));
    vector<vector<bool>> A(N, vector<bool>(N, false));

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        a--; b--;
        T[a][b] = true;
        T[b][a] = true;
    }

        for (int i = 0; i < M; i++) {
        cin >> a >> b;
        a--; b--;
        A[a][b] = true;
        A[b][a] = true;
    }

    vector<int> p(N);
    for (int i = 0; i < N; i++) p[i] = i;

    bool is_same = false;
    do {
        bool small_same = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (T[i][j] == A[p[i]][p[j]]) continue;
                else {
                    small_same = false;
                }
            }
        }
        if (small_same) {
            is_same = true;
        }

    } while (next_permutation(p.begin(), p.end()));

    if (is_same) {cout << "Yes" << endl;}
    else {cout << "No" << endl;}
    return 0;    

}
