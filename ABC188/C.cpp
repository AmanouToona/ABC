# include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(pow(2, N));
    for (int i = 0; i < pow(2, N); i++) {
        cin >> A[i];
    }

    int loser = -1;
    for (int i = 0; i < N; i++) {
        int left = -1;

        for (int j = 0; j < pow(2, N); j++) {
            if (A[j] == 0) continue;

            if (left == -1) {
                left = j; 
                continue;
            }

            if (A[left] < A[j]) {
                A[left] = 0;
                loser = left;
            }
            else {
                A[j] = 0;
                loser = j;
            }
            left = -1;
        }
    }
    cout << loser + 1 << endl;

}
