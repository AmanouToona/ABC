import sys

N = int(input())

ab = []

for i in range(N):
    a, b = map(int, sys.stdin.readline().strip().split())
    ab.append((a, b, i))

ab.sort(key=lambda x: x[0])

a_min = ab[0][0]
a_min_i = ab[0][2]

ab.sort(key=lambda x: x[1])

b_min_i = ab[0][2]

if a_min_i == b_min_i:
    ans = min(a_min + ab[0][1], max(a_min, ab[1][1]))
else:
    ans = max(a_min, ab[0][1])

print(ans)
