import sys
import math

N, X, T = map(int, sys.stdin.readline().strip().split())

ans = math.ceil(N / X) * T
print(ans)
