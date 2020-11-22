#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, x;
    string S;

    cin >> N >> x;
    cin >> S;

    int ans = x;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'o') {
            ans++;
        }
        else if (ans == 0) continue;
        else ans --;
    }

    cout << ans << endl;
}