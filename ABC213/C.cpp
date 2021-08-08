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
    int H, W, N;
    cin >> H >> W >> N;

    vector<pair<int, int>> A, B;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        A.push_back(make_pair(a, i));
        B.push_back(make_pair(b, i));
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    map<int, int> ma, mb;
    for (int i = 0; i < N; i++) {
        int a = A[i].first;
        if (ma.count(a) == 0) ma[a] = ma.size();

        int b = B[i].first;
        if (mb.count(b) == 0) mb[b] = mb.size();
    }

    vector<vector<int>> ans(N, vector<int>(2, 0));
    for (int i = 0; i < N; i++) {
        auto[a, num_a] = A[i];
        ans[num_a][0] = ma[a] + 1;

        auto[b, num_b] = B[i];
        ans[num_b][1] = mb[b] + 1;
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }

}
