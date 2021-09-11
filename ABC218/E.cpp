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


int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, pair<int, int>>> g;
    map<pair<int, int>, int> edge; // 多重辺の管理用
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        A--; B--;
        g.push_back(make_pair(-C, make_pair(A, B)));

        if (A > B) {
            edge[make_pair(B, A)]++;

        } else {
            edge[make_pair(A, B)]++;
        }
    }

    sort(g.begin(), g.end());
    
    UnionFind uf(N);

    ll ans = 0;
    
    for (int i = 0; i < M; i++) {
        if (g[i].first > 0) break;
        int A = g[i].second.first;
        int B = g[i].second.second;

        if (A > B) {
            int temp = A;
            A = B;
            B = temp;
        }

        edge[make_pair(A, B)] --;
        if (edge[make_pair(A, B)] == 0) {
            uf.unite(A, B);
        }
        if (uf.size(0) == N) break;
        ans -= g[i].first;
    }

    cout << ans << endl;

}