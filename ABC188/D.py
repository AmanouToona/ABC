import sys

N, C = map(int, sys.stdin.readline().strip().split())

cusum = [0] * (10 ** 9 + 2)
for i in range(N):
    a, b, c = map(int, sys.stdin.readline().strip().split())
    cusum[a] += c
    cusum[b + 1] -= c

for i in range(len(cusum) - 1):
    print(i)
    cusum[i + 1] += cusum[i]

ans = 0
for i in range(len(cusum)):
    ans += min(C, cusum(i))

print(ans)

