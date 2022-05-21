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

int const INF = INT_MAX;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, pair<int, int>>> edge;
    map<pair<int, int>, int> m;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back(make_pair(c, make_pair(a, b)));

        m[make_pair(a, b)] = i + 1;
    }

    sort(edge.begin(), edge.end(),
         [&](pair<int, pair<int, int>> i, pair<int, pair<int, int>> j) -> bool {
             return i.first < j.first;
         });

    UnionFind uf(N + 1);
    vector<int> ans;
    for (auto [c, e] : edge) {
        int a = e.first;
        int b = e.second;

        if (uf.same(a, b)) continue;
        uf.unite(a, b);
        ans.push_back(m[make_pair(a, b)]);
    }

    for (int i = 0; i < N - 1; i++) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}