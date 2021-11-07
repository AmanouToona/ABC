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
    int N;
    cin >> N;

    vector<int> T(N);
    vector<vector<int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i];

        int K;
        cin >> K;

        int a;
        for (int k = 0; k < K; k++) {
            cin >> a;
            A[i].push_back(a);
        }
    }

    vector<bool> learn(N, false);
    learn[N - 1] = true;

    queue<int> q;
    q.push(N);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v: A[u -1]) {
            if (!learn[v - 1]) {
                q.push(v);
                learn[v - 1] = true;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if(learn[i]) ans += T[i];
    }

    cout << ans << endl;
}
