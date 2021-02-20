#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    double X, Y, R;
    cin >> X >> Y >> R;

    ll xx = round(X * 10000);
    ll yy = round(Y * 10000);
    ll rr = round(R * 10000);

    xx %= 10000;
    yy %= 10000;

    ll left = 0, right = 1;
    ll ans = 0;
    for (int i = int(1e9); i > 0; i -= 10000) {
        while((i - yy) * (i - yy) + (right * 10000 - xx) * (right * 10000 - xx) <= rr * rr) ++right;
        while((i - yy) * (i - yy) + (left * 10000 - xx) * (left * 10000 - xx) <= rr * rr) --left;
        ans += right - left - 1;
    }

    left = 0; right = 1;
    for (int i = - int(1e9); i <= 0; i+= 10000) {
        while((i - yy) * (i - yy) + (right * 10000 - xx) * (right * 10000 - xx) <= rr * rr) ++right;
        while((i - yy) * (i - yy) + (left * 10000 - xx) * (left * 10000 - xx) <= rr * rr) --left;
        ans += right - left - 1;
    }
    
    cout << ans << endl;

    return 0;
}
