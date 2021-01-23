#include <bits/stdc++.h>
using namespace std;

int main() {
    long long f = 1, t = 1;

    int N ;
    string S;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S;
        if (S == "AND") {
            long long nt = t;
            long long nf = t + 2 * f;

            t = nt;
            f = nf;
        } else {
            long long nt = 2 * t + f;
            long long nf = f;

            t = nt;
            f = nf;
        }
    }
    cout << t <<endl;
    
}