import sys

# N = int(input())
# A = list(map(int, sys.stdin.readline().strip().split()))

S, T = map(int, sys.stdin.readline().strip().split())

ans = 0
for a in range(0, 101):
    for b in range(0, 101):
        for c in range(0, 101):
            if a + b + c > S:
                continue
            if a * b * c <= T:
                ans += 1

print(ans)
