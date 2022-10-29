import sys

N = int(input())
A = list(map(int, sys.stdin.readline().strip().split()))
A = sorted(A)

maxA = A[-1]
halfA = maxA // 2

ans = [False] * maxA
for i in range(N):
    if i != N - 1 and A[i + 1] == A[i]:
        continue
    if i != 0 and A[i - 1] == A[i]:
        continue
    ans[A[i] - 1] = True

for i in A:
    if i > halfA:
        break
    j = i + i
    while j <= maxA:
        ans[j - 1] = False
        j += i

print(sum(ans))
