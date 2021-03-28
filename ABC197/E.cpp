# include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int N;
    cin >> N;

    vector<vector<int>> color(N, vector<int>());

    for (int i = 0; i < N; i++) {
        int x, c;
        cin >> x >> c;
        color[c--].push_back(x);
    }

    vector<pair<int, int>> color_edge;
    color_edge.push_back(make_pair(0, 0));
    for (int i = 0; i < N; i++) {
        if (color[i].empty()) continue;

        sort(color[i].begin(), color[i].end());
        color_edge.push_back(make_pair(color[i][0], color[i][color[i].size() - 1]));
    }
    color_edge.push_back(make_pair(0, 0));




}