#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int V, T, S, D;
    cin >> V >> T >> S >> D;

    if (D >= V * T && D <= V * S) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

}