#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> t(8, vector<int>(8, 0));

    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> t.at(i).at(j);
        }
    }

    vector<int> p;
    for (int i = 1; i < N; i++) {
        p.push_back(i);
    }

    int ans = 0;
    do {
        int time = 0;
        time += t.at(0).at(p.at(0));
        for (int i = 1; i < p.size(); i++) {
            time += t.at(p.at(i - 1)).at(p.at(i));
        }
        time += t.at(p.at(p.size() - 1)).at(0);
        if (time == K) ans++ ;
    } while (next_permutation(p.begin(), p.end()));

    cout << ans << endl;
    

}
