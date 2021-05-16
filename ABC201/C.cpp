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
    string S;
    cin >> S;

    int o=0, x=0, q=0;
    for (auto s: S) {
        if (s == 'o') o++;
        else if (s == 'x') x++;
        else q++;
    }
    
    if (o > 4 || x == 10) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < 10000; i++) {
        stringstream lock_ss;
        lock_ss  << setfill('0') << setw(4) << i;
        string lock;
        lock_ss >> lock;

        bool can = true;
        // 禁止文字のチェック
        for (int j = 0; j < 10; j++) {
            char check = '0' + j;
            if (S[j] == 'x' && lock.find(check) != string::npos){
                can = false;
                break;
            }
        }

        // 含有文字の確認
        for (int j = 0; j < 10; j++) {
            char check = '0' + j;
            if (S[j] == 'o' && lock.find(check) == string::npos) {
                can = false;
                break;
            }
        }

        if (can) ans++;

    }

    cout << ans << endl;

}