#include <bits/stdc++.h>
using namespace std;

int main() { 
    int N, W;
    cin >> N >> W;

    vector<long long> cusum(200001); 
    for(int i = 0; i < N; i++) {
        int s, t, p;
        cin >> s >> t >> p;

        cusum[s] += p;
        cusum[t] -= p;
    }

    for (int i = 0; i < cusum.size() - 1; i++) {
        cusum[i + 1] += cusum[i];
    }

    for (int i = 0; i < cusum.size(); i++) {
        if (cusum[i] > W) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

}
