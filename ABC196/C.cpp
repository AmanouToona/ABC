#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll pow_ll(ll x, ll y) {
    ll ret = 1;
    while (y > 0) {
        if (y & 1) ret *= x;
        x *= x;
        y >>= 1;
    }
    return ret;
}

int const INF = INT_MAX;


int main() {
    ll N;
    cin >> N;

    string Nst = to_string(N);
    int digit = to_string(N).length();

    int ans = 0;

    if (digit % 2 == 0) {
        string half1, half2;
        for (int i = 0; i < digit / 2; i++){
            half1.push_back(Nst[i]);
            half2.push_back(Nst[digit / 2 + i]);
        }

        int half11 = stoi(half1);
        int half22 = stoi(half2);

        if (half11 <= half22) {
            ans += half11;
        } else {
            ans += half11 - 1;
        }
    } 
    else {
        for (int i = 0; i < digit / 2; i++) {
            ans += pow_ll(10, i) * 9;
        }   
    }

    cout << ans << endl;

}

/*
100000000000
10000000000
*/
