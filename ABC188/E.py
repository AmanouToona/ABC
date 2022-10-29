import sys

N, M = map(int, sys.stdin.readline().strip().split())

A = list(map(int, sys.stdin.readline().strip().split()))

road = []
for _ in range(M):
    X, Y = map(int, sys.stdin.readline().strip().split())
    road.append((X - 1, Y - 1))

road = sorted(road)

town = [[a, a] for a in A]

for x, y in road:
    if town[y][0] > town[x][0]:
        town[y][0] = town[x][0]

ans = 0

for a, b in town:
    if b - a > ans:
        ans = b - a

if ans != 0:
    print(ans)
    sys.exit()

ans = -(10 ** 10)
for x, y in road:
    ans = max(ans, A[y] - A[x])
print(ans)
