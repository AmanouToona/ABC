#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf=1001001001;
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> d(N, vector<int>(N, inf));

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a - 1][b - 1] = min(c, d[a - 1][b - 1]);
    }



    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                d[i][j] = min(d[i][j], (d[i][k] + d[k][j]));
            }
        }
    }

    for (int i = 0; i < N; i ++){
        if (d[i][i] < inf) {
            cout << d[i][i] << endl;
        } else{
            cout << -1 << endl;
        }
    }
}

