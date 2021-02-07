#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> S;
    for (int i = 0; i < H; i++) {
        string s;
        cin >> s;
        S.push_back(s);
    }

    int ans = 0;
    for (int h = 0; h < H  - 1; h++) {
        for (int w = 0; w < W - 1; w++) {
            int count = 0;
            for (int hp = 0; hp <=1; hp++) {
                for (int wp=0; wp <=1; wp++) {
                    if (S[h + hp][w + wp] == '#') count++;
                }
            }
            if (count == 1 || count == 3) {
                ans ++;
            }
        }

    }

    cout << ans << endl;

}

/*
5 5
.....
..#..
.###.
..#..
.....

*/

/*
5 6
......
..#...
.####.
..#...
......

*/
