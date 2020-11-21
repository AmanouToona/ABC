#include <bits/stdc++.h>
using namespace std;

int main() {
    double sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;

    double ans, a;
    a = (-gy - sy) / (gx - sx);
    ans = - sy / a + sx;

    // cout << ans << endl; 
    printf("%.10f\n", ans);

}
