#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const double pi = 3.141592653589793;

int main() {
    long double N;
    cin >> N;

    long double x0, y0, xh, yh;
    cin >> x0 >> y0 >> xh >> yh;

    long double vx = xh - x0;
    long double vy = yh - y0;

    long double theta = 180 + 360 / N;
    theta = (pi * theta / 180) * (-1);
    long double vx2 = vx * cos(- theta) - vy * sin(-theta);
    long double vy2 = vx * sin(- theta) + vy * cos(- theta); 

    long double ansx = x0 + vx / 2 + vx2 / 2;
    long double ansy = y0 + vy / 2 + vy2 / 2;

    cout << fixed << setprecision(10) << ansx << " " << ansy << endl; 

}
