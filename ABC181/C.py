import sys
sys.setrecursionlimit(10 ** 9)

N = int(input())

point = []
for n in range(N):
    x, y = map(int, sys.stdin.readline().strip().split())
    point.append((x, y))

def solve(p1, p2, p3):
    v1 = (p1[0] - p2[0], p1[1] - p2[1])
    v2 = (p1[0] - p3[0], p1[1] - p3[1])

    if v1[0] * v2[1] == v1[1] * v2[0]:
        return True
    else:
        False

    # size_v1 = abs((v1[0] ** 2 + v1[1] ** 2) ** 0.5)
    # size_v2 = abs((v2[0] ** 2 + v2[1] ** 2) ** 0.5)

    # v1v2 = v1[0] * v2[0] + v1[1] * v2[1]

    # if abs(v1v2) / (size_v1 * size_v2) == 1:
    #     return True
    # else:
    #     return False


for i in range(N):
    for j in range(i + 1, N):
        for k in range(j + 1, N):
            if solve(point[i], point[j], point[k]):
                print('Yes')
                sys.exit()

print('No')
