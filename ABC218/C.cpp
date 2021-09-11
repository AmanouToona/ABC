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


vector<pair<int, int>> rotate(vector<pair<int, int>> s) {
    vector<pair<int, int>> res;

    for (auto[y, x]: s) {
        res.push_back(make_pair(x, -y));
    }

    return res;

}



int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> S, T;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char ij;
            cin >> ij;
            if (ij == '#') S.push_back(make_pair(i, j));
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char ij;
            cin >> ij;
            if (ij == '#') T.push_back(make_pair(i, j));
        }
    }

    sort(S.begin(), S.end());
    sort(T.begin(), T.end());

    for (int i = 0; i < 4; i++) {
        if (i != 0) {
            S = rotate(S);
            sort(S.begin(), S.end());
        }

        int diff_x = S[0].second - T[0].second;
        int diff_y = S[0].first - T[0].first;

        for (int j = 0; j < S.size(); j++) {
            S[j].second -= diff_x;
            S[j].first -= diff_y;
        }

        if (S == T) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

}
