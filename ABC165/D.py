import sys
from math import floor

A, B, N = map(int, sys.stdin.readline().strip().split())

"""
理屈
求める答えは、　floor(A * (x/B の小数部)) に式変形できる。
つまり、　x/B の小数部を最大にすればよい。
少数の最大値は、1に限りなく近い値のこと。
この値をとるのは、x/B の余りが限りなくBに近いとき。
つまり、x/B の余りを最大にするx が求める値を最大にするx である。
"""

if N < B:
    print(floor(A * (N / B - floor(N / B))))
else:
    print(floor(A * ((B - 1) / B - floor((B - 1) / B))))
