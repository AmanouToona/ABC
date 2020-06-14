import sys

A, B, C, K = map(int, sys.stdin.readline().strip().split())

a = min(A, K)
b = min(B, K - a)
c = min(C, K - b - a)

print(a - c)
