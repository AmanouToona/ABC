#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int const mod = 998244353;

ll pow_ll(ll x, ll y) {
    ll ret = 1;
    while (y > 0) {
        if (y & 1) ret *= x;
        ret %= mod;
        x *= x;
        x %= mod;
        y >>= 1;
    }
    return ret;
}

int const INF = INT_MAX;


int count_loop(vector<int> & idx) {
    int N = idx.size();

    vector<bool> fp(N, false);
    int res = 0;
    
    for (int i = 0 ; i < N; i++) {
        if (fp[i]) continue;
        
        int loop = 0;
        queue<int> q;
        fp[i] = true;
        q.push(i);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            int v = idx[u];

            if (fp[v]) break;
            fp[v] = true;
            q.push(v);
            loop++;
        }

        res = max(res, loop);
    }

    return res;
}


int main() {
    int N, K;
    cin >> N >> K;

    vector<int> idx(N);
    for (int i = 0; i < N; i++) idx[i] = i;

    int ans = 0;
    do {
        int loop = count_loop(idx);
        loop ++;
        ans += pow_ll(loop, K);

    } while(std::next_permutation(idx.begin(), idx.end()));
     
    cout << ans << endl;
}