#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cusum(ll left, ll right) {
    ll res = (left + right) * (right - left + 1) / 2;
    return res;
}


int main() {
    ll N;
    cin >> N;

    if (N % 2 == 1) {
        
        int ans = 0;
        ll right = 1;
        while(true) {
            if (cusum(1, right) <= N) {
                ans ++;
                if (right == 1 || right == 2) {
                    right++;
                } else {right += 2;}
            } else {break;}
            
        }
        cout << ans * 2 << endl; 
        return 0;
    }

    int ans = 0;
    ll right = 2;
    while(true) {
        if (right % 2 == 1) {
            if (cusum(2, right) <= N) {
                ans ++;
                right++;
            } else {break;}
            
        } else {
        if (cusum(1, right) <= N) {
            ans ++;
            right++;
        } else {break;}
        }

    }
    cout << ans * 2 << endl;   
}