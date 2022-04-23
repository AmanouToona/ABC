#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> P(N);
    for (int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
        P[i] = make_pair(X, Y);
    }

    if (K == 1) {
        cout << "Infinity" << endl;
        return 0;
    }

    map<tuple<int, int, ll>, int> m;  // a, b, 切片みたいな値
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int a = P[j].first - P[i].first;    // x
            int b = P[j].second - P[i].second;  // y

            if (a < 0) {
                a = -a;
                b = -b;
            }

            if (a == 0) {
                b = 1;
            } else {
                int g = gcd(a, b);
                a /= g;
                b /= g;
            }
            ll c = ((ll)P[i].first) * b - ((ll)P[i].second) * a;

            m[{a, b, c}]++;
        }
    }

    int ans = 0;
    for (auto p : m) {
        if (p.second >= K * (K - 1) / 2) ans++;
    }
    cout << ans << endl;
}
