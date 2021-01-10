# include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    long long inner = 0;
    for (int i = 0; i < N; i++) {
        inner += A[i] * B[i];
    }

    if (inner == 0) {cout << "Yes" << endl;}
    else {cout << "No" << endl;};
    
}
