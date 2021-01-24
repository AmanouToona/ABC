#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    deque<pair<int, int>> que;  // height, i

    int A;
    int score = 0;
    for (int i = 0; i < N; i++) {
        cin >> A;
        int left = i;
        while(!que.empty() && que.back().first > A) {
                int box = que.back().first * (i - que.back().second);
                score = max(score, box);
                left = que.back().second;
                que.pop_back();
            }
        que.push_back(make_pair(A, left));
    }

    while(!que.empty()) {
        int box = que.back().first * (N - que.back().second);
        score = max(score, box);
        que.pop_back();
    }

    cout << score << endl;
}