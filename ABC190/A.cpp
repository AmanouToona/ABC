#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string t="Takahashi", a = "Aoki";
    int A, B, C;
    cin >> A >> B >> C;

    if (C == 0) {
        if (A - B > 0) {
            cout << t << endl;
            return 0;
        } else {
            cout << a << endl;
            return 0;
        }
    }

    if (B - A > 0) {
        cout << a << endl;
        return 0;
    }

    cout << t << endl;

}