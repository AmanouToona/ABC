# include <bits/stdc++.h>
using namespace std;

// long day = 1000000000 + 1;
long long day = 536870911;

vector<long long> cusum(day);

int main() {
    int N, C;
    cin >> N >> C;

    cout << cusum.max_size();

    int a, b, c;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        cusum[a] += c;
        cusum[b + 1] -= c;
    }

    for (long i = 0; i < day; i++) {
        cusum[i + 1] += cusum[i];
    }

    long long ans = 0;
    for (long i = 0; i < day; i++) {
        if (cusum[i] <= C) {ans += cusum[i];}
        else {ans += C;};
    };

    cout << ans << endl;

}
