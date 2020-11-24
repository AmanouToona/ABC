#include<bits/stdc++.h>
using namespace std;

const int INF = 1001001;

int main() {
    int H, W;
    cin >> H >> W;

    string s;
    vector<string> table;
    for (int i = 0; i < H; i++) {
        cin >> s;
        table.push_back(s);
    }

    // vector<pair<int, int>> warp(26);
    map<char, vector<pair<int, int>>> warp;
    pair<int, int> start, goal;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (isalpha(table[h][w]) && islower(table[h][w])) {
                warp[table[h][w]].push_back(make_pair(h, w));
            } else if (table[h][w] == 'S') start = make_pair(h, w);
            else if (table[h][w] == 'G') goal = make_pair(h, w);
        }
    }

    queue<pair<int, int>> q;
    q.emplace(start);
    vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> dist(H, vector<int>(W, INF));
    // vector dist(H, vector(W, INF));
    dist[start.first][start.second] = 0;

    while(!q.empty()) {

        int hu = q.front().first;
        int wu = q.front().second;
        q.pop();

        if (hu == goal.first && wu == goal.second) {
            cout << dist[hu][wu] << endl;
            return 0;
        }


        for (auto du :  d) {
            int hv = hu + du.first;
            int wv = wu + du.second;

            if (hv < 0 || hv >= H || wv < 0 || wv >= W) continue;
            if (table[hv][wv] == '#') continue;

            if (dist[hv][wv] != INF) continue;

            dist[hv][wv] = dist[hu][wu] + 1;
            q.emplace(hv, wv);
        }
        
        // warp 処理
        if (isalpha(table[hu][wu]) && islower(table[hu][wu])) {
            for (auto [h, w] : warp[table[hu][wu]]) {
                if (dist[h][w] != INF) continue;
                dist[h][w] = dist[hu][wu] + 1;
                q.emplace(h, w);
            }
            warp[table[hu][wu]] = {};
        }


    }
    cout << -1 << endl;

}