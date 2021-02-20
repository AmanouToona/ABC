#include <bits/stdc++.h>
using namespace std;

int g1(int a) {
    string a_st = to_string(a);

    vector<int> a_int;
    for (auto a_ch: a_st){
        a_int.push_back(a_ch - '0');
    }

    sort(a_int.begin(), a_int.end());
    int ans = 0;
    for (int i = 0; i < a_int.size(); i++){
        ans += pow(10, i) * a_int[i];
    }
    return ans;
}

int g2(int a) {
    string a_st = to_string(a);

    vector<int> a_int;
    for (auto a_ch: a_st) {
        a_int.push_back(a_ch - '0');
    }

    sort(a_int.begin(), a_int.end(), greater<int>{});
    int ans = 0;

    for (int i = 0; i < a_int.size(); i++) {
        ans += pow(10, i) * a_int[i];
    }
    return ans;
}


int main() {
    int N, K;

    cin >> N >> K;

    int ans = N;
    for (int i = 0; i < K; i++) {
        ans = g1(ans) - g2(ans);
    }
    cout << ans << endl;
}