import sys

N, K = map(int, sys.stdin.readline().strip().split())

P = list(map(int, sys.stdin.readline().strip().split()))

P.sort()

ans = sum(P[:K])
print(ans)
