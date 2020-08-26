import sys

N = int(input())
A = list(map(int, sys.stdin.readline().strip().split()))

ans = 0
tall = A[0]

for a in A:
    if a > tall:
        tall = a
    else:
        ans += tall - a

print(ans)
