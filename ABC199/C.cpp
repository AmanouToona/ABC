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
    string S;
    cin >> S;
    int Q;
    cin >> Q;

    bool rev = false;
    for (int i = 1; i <= Q; i++) {
        int T, A, B;
        cin >> T >> A >> B;
        A--; B--;

        if (rev) {
            A = (A + N) % (2 * N);
            B = (B + N) % (2 * N);
        }

        if (T == 1) {
            char temp = S[A];
            S[A] = S[B];
            S[B] = temp;
        } else {
            if (rev) rev = false;
            else rev = true;
        }
    }

    string ans = "";
    if (rev) {
        for (int i = 0; i < N; i++) {
            ans.push_back(S[N + i]);
        }
        for (int i = 0; i < N; i++) {
            ans.push_back(S[i]);
        }
    } else {
        ans = S;
    }
    cout << ans << endl;
}   
