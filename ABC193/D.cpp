#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll score (string s) {
    vector<int> cards(9);
    for (int i = 0; i < s.size(); i++) {
        cards[s[i] - '0' - 1]++;
    }

    ll ans = 0;
    for (int i = 1; i < 10; i++) {
        ans += i * pow(10, cards[i - 1]);
        cout << (i * pow(10, cards[i - 1])) << " " << ans << endl;
    }
    return ans;
}


int main() {
    int K;
    string S, T;

    cout << score("11449") << endl;
}
