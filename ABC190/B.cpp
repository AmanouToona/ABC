#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, S, D;
    cin >> N >> S >> D;

    int flag = 0;
    for (ll i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        if (x >= S || y <= D) {
            continue;
        }
        flag = 1;
    }

    if (flag == 0) {
    cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    
}