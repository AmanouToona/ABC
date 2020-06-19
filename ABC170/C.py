import sys

X, N = map(int, sys.stdin.readline().strip().split())
P = list(map(int, sys.stdin.readline().strip().split()))

i = 0
while True:
    ans = X - i
    if ans not in P:
        break

    ans = X + i
    if ans not in P:
        break

    i += 1

print(ans)
