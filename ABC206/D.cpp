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

    vector<int> A(N);
    for (int i=0; i < N; i++) {
        cin >> A[i];
    }

    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> a1(N / 2), a2(N / 2);
    for (int i = 0; i < N / 2; i++) {
        a1[i] = A[i];
        a2[i] = A[(N + 1) / 2+ i];
    }
    reverse(a2.begin(), a2.end());

    set<pair<int, int>> s;
    for (int i = 0; i < N / 2; i++) {
        int a = a1[i];
        int b = a2[i];
        if (a == b) continue;
        if (a > b) swap(a, b);
        s.insert(make_pair(a, b));
    }    

    set<int> a, b;
    for (auto p: s) {
        a.insert(p.first);
        b.insert(p.second);
    }

    int ans = s.size();
    for(auto bb: b) {
        if (a.count(bb)) ans--;
    }

    // int ans = max(a.size(), b.size());
    cout << ans << endl;

}

/*
4
1 3 2 4

6
2 2 3 6 3 5


*/

