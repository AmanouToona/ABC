#include <bits/stdc++.h>
using namespace std;
using ll = long long;


class UnionFind {
    vector<int> p, rank, member_size;
    int comp;

    public: UnionFind(int n): p(n), rank(n, 0), member_size(n, 1){
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        comp = n;
    }

    int c() {
        return comp;
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
        comp--;
        return;
    } 
    
    int same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return member_size[find(x)];
    }

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
    int N, M;
    cin >> N >> M;

    vector<vector<int>> g(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    UnionFind uf(N);

    vector<int> ans(N, 0);
    int cnt = 0;
    for (int i = N - 1; i > 0; i--) {

        if (uf.find(i) != i) cnt--;

        for (int v: g[i]) {
            if (v < i) continue;
            uf.unite(i, v);
        }
        ans[i - 1] = uf.c() - i;
    }

    for (int a: ans) {
        cout << a << endl;
    }

}