#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    deque<pair<int, int>> que;  // height, masu

    int a = 0, A;
    int left, right, score;
    que.push_back(make_pair(1, 0));
    for (int i = 0; i < N; i++) {
        cin >> A;
        if (A < a) {
            for (int h = A; h > a; a--){
                while(h < que.back().first()) {

                }
            }
        }

        que.push_back(make_pair(a, i));
        a = A;
    }

}