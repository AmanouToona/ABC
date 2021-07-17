#include<bits/stdc++.h>
using namespace std;
using ll = long long;


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
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> a1(N / 2), a2(N / 2);
    for (int i = 0; i < N / 2; i++) {
        a1[i] = A[i];
        a2[i] = A[(N + 1) / 2+ i];
    }
    reverse(a2.begin(), a2.end());

    int a_max = *max_element(A.begin(), A.end());

    UnionFind uf(a_max + 1);

    for (int i = 0; i < N / 2; i++) {
        uf.unite(a1[i], a2[i]);
    }


    int ans = 0;
    for (int i = 1; i <= a_max; i++) {
        if (i != uf.find(i)) continue;
        if (uf.size(i) == 0) continue;

        ans += uf.size(i) - 1;
    }

    cout << ans << endl;

}
