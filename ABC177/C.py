import sys
import math

big = 10 ** 9 + 7

N = int(input())
A = list(map(int, sys.stdin.readline().strip().split()))
sum_A = sum(A)

ans = 0
for i in range(1, len(A)):
    sum_A -= A[i - 1]
    ans += A[i - 1] * sum_A

print(ans % big)
