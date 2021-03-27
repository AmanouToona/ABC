#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int H, W, X, Y;
    cin >> H >> W >> X >> Y;
    X--;
    Y--;

    vector<string> table(H);
    for (int h = 0; h < H; h++) {
        cin >> table[h];
    }

    int ans = 1;
    int dh = 0, dw = 0;    

    if (table[X][Y] == '#') {
        cout << 0 << endl;
        return 0;
    }



    dh = 1;
    while (X - dh >= 0) {
        if (table[X - dh][Y] == '#') break;
        ans++;
        dh++;
    }

    dh = 1;
    while (X + dh < H) {
        if (table[X + dh][Y] == '#') break;
        ans++;
        dh++;
    }

    dw = 1;
    while(Y - dw >= 0) {
        if (table[X][Y - dw] == '#') break;
        ans++;
        dw++;
    }

    dw = 1;
    while(Y + dw < W){
        if (table[X][Y + dw] == '#') break;
        ans++;
        dw++;
    }

    cout << ans << endl;



}