#include<bits/stdc++.h>
using namespace std;

double f[100 + 1][100 + 1][100 + 1];

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    for (int a = 99; a >= 0; a--){
        for (int b = 99; b >= 0; b--){
            for (int c = 99; c >= 0; c--) {
                if (a + b + c == 0) continue;
                double now = 0;
                now += f[a + 1][b][c] * a;
                now += f[a][b + 1][c] * b;
                now += f[a][b][c + 1] * c;
                f[a][b][c] = now / (a + b + c) + 1;
            }
        }
    }

    printf("%.10f\n", f[A][B][C]);
    return 0;
}