#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class UnionFind {
    vector<int> p, rank, member_size;

   public:
    UnionFind(int n) : p(n), rank(n, 0), member_size(n, 1) {
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }

    int find(int x) {
        if (p[x] == x) return x;
        p[x] = find(p[x]);
        return p[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return;

        if (rank[x] <= rank[y]) {
            p[x] = y;
            member_size[y] += member_size[x];
        } else {
            p[y] = x;
            member_size[x] += member_size[y];
        }

        if (rank[x] == rank[y]) {
            rank[y]++;
        }
        return;
    }

    int same(int x, int y) { return find(x) == find(y); }

    int size(int x) { return member_size[find(x)]; }
};

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
    int N, Q;
    cin >> N >> Q;

    vector<int> X(N);
    for (int i = 0; i < N; i++) cin >> X[i];

    UnionFind uf(N);
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        uf.unite(A, B);
    }

    map<int, int> m;
    for (int i = 0; i < N; i++) {
        int p = uf.find(i);
        if (m.count(p) == 0) m[p] = m.size();
    }

    vector<vector<int>> precalc(m.size(), vector<int>());
    for (int i = 0; i < N; i++) {
        precalc[m.at(uf.find(i))].push_back(X[i]);
    }

    for (int i = 0; i < precalc.size(); i++) {
        sort(precalc[i].begin(), precalc[i].end(), greater<int>());
    }

    for (int i = 0; i < Q; i++) {
        int V, K;
        cin >> V >> K;

        V--;
        K--;
        cout << precalc[m.at(uf.find(V))][K] << endl;
    }
}
