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
    string S, T;
    cin >> S >> T;

    bool can = true;
    if (S.size() != T.size()) {
        cout << "No" << endl;
        return 0;
    }

    for (int i = 0; i < S.size(); i++) {
        if (S[i] != T[i]) {
            swap(T[i], T[i + 1]);
            break;
        }
    }

    for (int i = 0; i < S.size(); i++) {
        if (S[i] != T[i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;


    // int count = 0;
    // for (int i = 0; i < S.size() - 1; i++) {
    //     if (S[i] == T[i]) continue;
    //     if (count == 1) can = false;
    //     count++;
    //     if (S[i + 1] == T[i] && S[i] == T[i + 1]) i++;

}