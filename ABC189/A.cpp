#include <bits/stdc++.h>
using namespace std;

int main() {
    string C;
    cin >> C;

    for (int i = 0; i < 2; i++) {
        if (C[i] != C[i + 1]) {
            cout << "Lost" << endl;
            return 0;
        }
    }
    cout << "Won" << endl;
}