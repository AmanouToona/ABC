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


string conv(string &S, map<char, int> &m) {
    string res = "";
    for (auto s: S) {
        res.push_back(m[s] + 'a');
    }
    return res;
}


int main() {
    string X;
    cin >> X;

    map<char, int> m;
    for (char x: X) m[x] = m.size();

    int N;
    cin >> N;

    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    vector<pair<string, string>> S2;
    for (int i = 0; i < N; i++) {
        S2.push_back(make_pair(conv(S[i], m), S[i]));
    }

    sort(S2.begin(), S2.end());
    for (auto s: S2) {
        cout << s.second << endl;
    }

}
