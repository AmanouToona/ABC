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
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int Q;
    cin >> Q;
    vector<tuple<int, int, int, int>> query;
    for (int q = 0; q < Q; q++) {
        int L, R, X;
        cin >> L >> R >> X;
        L--;
        R--;
        query.push_back(make_tuple(L, R, X, q));
    }

    vector<int> ql(Q, 0);
    vector<int> qr(Q, 0);
    map<int, int> m;

    sort(query.begin(), query.end(),
         [&](tuple<int, int, int, int> i, tuple<int, int, int, int> j) -> bool {
             return get<0>(i) < get<0>(j);
         });

    int q = 0;
    for (int i = 0; i < N; i++) {
        while (q < Q && get<0>(query[q]) <= i) {
            ql[get<3>(query[q])] = m[get<2>(query[q])];
            q++;
        }
        int a = A[i];
        if (m.count(a) == 0)
            m[a]++;
        else
            m[a]++;
    }

    sort(query.begin(), query.end(),
         [&](tuple<int, int, int, int> i, tuple<int, int, int, int> j) -> bool {
             return get<1>(i) < get<1>(j);
         });

    q = 0;
    map<int, int> mm;
    for (int i = 0; i < N; i++) {
        int a = A[i];
        if (mm.count(a) == 0)
            mm[a]++;
        else
            mm[a]++;

        while (q < Q && get<1>(query[q]) <= i) {
            qr[get<3>(query[q])] = mm[get<2>(query[q])];
            q++;
        }
    }

    for (int q = 0; q < Q; q++) {
        cout << qr[q] - ql[q] << endl;
    }
}
