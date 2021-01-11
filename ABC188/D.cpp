# include <bits/stdc++.h>
using namespace std;

// imos 法ではサイズが大きすぎる

int main() {
    long long N, C;
    cin >> N >> C;

    vector<pair<int, int>> event;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        event.emplace_back(a - 1, c);
        event.emplace_back(b, -c);
    }

    sort(event.begin(), event.end());

    long long cost = 0, ans = 0, left_day = event[0].first;
    for (auto [x, y]: event) {
        ans += min(cost, C) * (x - left_day);
        cost += y;
        left_day = x;
    }
    cout << ans << endl;

}
