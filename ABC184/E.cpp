#include<bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> table;
    for (int i = 0; i < H; i++) {
        string s;
        table.push_back(s);
    }

    map<char, vector<pair<int, int>>> warp;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (isalpha(table[h][w])) {
                warp[table[h][w]].push_back((h, w));
            }
        }
    }

}