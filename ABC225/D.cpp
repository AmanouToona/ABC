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
    int N, Q;
    cin >> N >> Q;

    vector<int> trainc(N, -1);  // 子を保存する
    vector<int> trainp(N, -1);  // 親を保存する

    for (int q = 0; q < Q; q++) {
        int c, x, y;
        cin >> c;
        if (c == 1) {
            cin >> x >> y;
            x--; y--;

            trainc[x] = y;
            trainp[y] = x;

        } else if (c == 2) {
            cin >> x >> y;
            x--; y--;

            trainc[x] = -1;
            trainp[y] = -1;

        } else {
            cin >> x;
            x--;

            // train x の親を辿れるところまで辿る
            int p = x;
            while (1) {
                if (trainp[p] == -1) break;
                p = trainp[p];
            }

            vector<int> output;
            output.push_back(p + 1);
            while (1) {
                if (trainc[p] == -1) break;
                output.push_back(trainc[p] + 1);
                p = trainc[p];
            }

            cout << output.size() << " ";
            for (int i = 0; i < output.size(); i++) {
                cout << output[i];
                if (i != output.size() - 1) {cout << " ";}
                else {cout << endl;}
            }
        }
    }
}
