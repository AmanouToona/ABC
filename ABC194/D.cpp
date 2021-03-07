#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long double pow_ll(long double x, ll y) {
    long double ret = 1;
    while (y > 0) {
        if (y & 1) ret *= x;
        x *= x;
        y >>= 1;
    }
    return ret;
}

int const INF = INT_MAX;


int main() {
    long double N, ans;
    cin >> N;

    long double temp = 1;

    if (N != 2){
    temp = pow_ll((N - 1) / N, N - 1);}

    for (int i = N - 1; i < 10000000; i++) {
        ans += i * 
    }

    cout << ans << endl;
    return 0;

}
