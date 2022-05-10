#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;

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

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    int notsame = 0;
    vector<pair<int, int>> ans;
    set<int> seta;   // A \ B
    set<int> setb;   // B \ A
    set<int> setab;  // A ^ B
    int R = 0;
    for (int i = 0; i < N; i++) {
        int a = A[i];

        if (setab.count(a)) {
            ans.push_back(ans.back());
            continue;
        }

        if (seta.count(a)) {
            ans.push_back(ans.back());
            continue;
        }

        if (setb.count(a)) {
            setb.erase(a);
            setab.insert(a);
        } else {
            seta.insert(a);
        }

        while (R < N && setb.size() == 0 && seta.size() != 0) {
            int b = B[R];

            if (setb.count(b) || setab.count(b)) {
                R++;
                continue;
            }

            if (seta.count(b)) {
                seta.erase(b);
                setab.insert(b);
            } else {
                setb.insert(b);
            }
            R++;
        }

        if (setb.size() || seta.size()) {
            ans.push_back(make_pair(R, R));
            continue;
        }

        int L = R - 1;
        while (R < N && setab.count(B[R])) {
            R++;
        }
        ans.push_back(make_pair(L, R));
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        if (ans[x].first <= y && ans[x].second > y) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}