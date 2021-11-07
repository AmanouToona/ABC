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


class UnionFind {
    vector<int> p, rank, member_size;

    public: UnionFind(int n): p(n), rank(n, 0), member_size(n, 1){
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
    
    int same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return member_size[find(x)];
    }

};


int const INF = INT_MAX;
int const mod = 998244353;


int count_loop(vector<vector<int>> &g, int start) {
    vector<bool> fp(g.size(), false);
    queue<int> q;

    q.push(start);
    fp[start] = true;

    int edges = 0, nodes = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        edges += g[u].size();
        nodes ++;

        for(int v: g[u]) {
            if (fp[v]) continue;
            q.push(v);
            fp[v] = true;
        }
    }

    return edges / 2 - nodes + 1;
}


int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> g(N);
    UnionFind uf(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);

        uf.unite(u, v);
    }

    map<int, int> search;
    int ans = 1;
    for (int i = 0; i < N; i++) {
        if (search.count(uf.find(i))) continue;
        search[uf.find(i)] = 1;

        int loops = count_loop(g, uf.find(i));

        if (loops == 1) {
            ans *= 2;
            ans %= mod;
        } else {
            ans *= 0;
        }
    }
    
    cout << ans << endl;

}