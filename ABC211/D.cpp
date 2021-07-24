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

ll const MOD = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;

        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    vector<vector<ll>> fp(N, vector<ll>(2, 0));  // 到達時間, 到達方法
    for (int i = 0; i < N; i++) {
        fp[i][0] = INF;
    }
    fp[0][0] = 0;
    fp[0][1] = 1;

    queue<int> q;
    for (int v: graph[0]) {
        q.push(v);
        fp[v][0] = 1;
        fp[v][1]++;
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        int time_u = fp[u][0];
        int time_v = time_u + 1;

        for (int v: graph[u]) {
            if (fp[v][0] < time_v) continue;
            else if (fp[v][0] == time_v) {
                fp[v][1] += fp[u][1];
                fp[v][1] %= MOD;
            } else {
                fp[v][0] = time_v;
                fp[v][1] = fp[u][1];
                q.push(v);
            }
        }
    }

    cout << fp[N - 1][1] << endl;

}

/*
4 5
2 4
1 2
2 3
1 3
3 4

*/
