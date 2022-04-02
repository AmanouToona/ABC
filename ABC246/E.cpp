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

    int a1, a2;
    cin >> a1 >> a2;
    a1--;
    a2--;
    int b1, b2;
    cin >> b1 >> b2;
    b1--;
    b2--;

    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    queue<pair<int, int>> q;
    q.push(make_pair(a1, a2));

    vector<vector<int>> fp(N, vector<int>(N, INF));
    fp[a1][a2] = 0;

    vector<int> dx = {1, 1, -1, -1};
    vector<int> dy = {-1, 1, -1, 1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        if (x == b1 && y == b2) break;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int vx = x;
            int vy = y;
            while (1) {
                vx += dx[i];
                vy += dy[i];
                if (vx >= N || vx < 0) break;
                if (vy >= N || vy < 0) break;
                if (S[vx][vy] == '#') break;
                if (fp[vx][vy] < INF) break;
                fp[vx][vy] = fp[x][y] + 1;
                q.push(make_pair(vx, vy));
            }
        }
    }

    if (fp[b1][b2] != INF) {
        cout << fp[b1][b2] << endl;
    } else {
        cout << -1 << endl;
    }
}