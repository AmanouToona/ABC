import sys

N = int(input())
A = list(map(int, sys.stdin.readline().strip().split()))

a_sum = sum(A)
ans = 0
for i in range(N - 1):
    a_sum -= A[i]
    ans -= 2 * A[i] * a_sum

for i in range(N):
    ans += (N - i - 1 + i) * A[i] ** 2

print(ans)