import sys
from math import sqrt

sys.setrecursionlimit(10 ** 8)


def get_dist(point1, point2):
    res = sqrt((point1[0] - point2[0]) ** 2 + (point1[1] - point2[1]) ** 2)
    return res


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    points = []
    for _ in range(N):
        x, y = map(int, sys.stdin.readline().strip().split())
        points.append((x, y))

    for _ in range(M):
        p, q = map(int, sys.stdin.readline().strip().split())
        points.append((p, q))

    dp = [[float("inf")] * (N + M) for _ in range(1 << (N + M))]

    points.reverse()
    for i, point in enumerate(points):
        dp[1 << i][i] = get_dist((0, 0), point)

    # 状態は 原点 街 宝箱 の順番
    for s in range(1 << (N + M)):
        for v in range(N + M):
            for u in range(N + M):
                if u == v:
                    continue
                if (s >> v) & 1:
                    continue
                if (s >> u) & 1 == 0 and s != 0:
                    continue

                speed = 1
                for i in range(M):
                    if (s >> i) & 1:
                        speed *= 2

                dist = get_dist(points[u], points[v])
                time = dist / speed

                dp[s | (1 << v)][v] = min(dp[s | (1 << v)][v], dp[s][u] + time)

    goal = 0
    for i in range(M, N + M):
        goal += 1 << i

    ans = float("inf")
    for i in range(1 << M):
        goal_ = goal + i

        speed = 1
        for i in range(M):
            if (goal_ >> i) & 1:
                speed *= 2

        for j in range(len(points)):
            if not (goal_ >> j) & 1:
                continue

            ans = min(ans, dp[goal_][j] + get_dist((0, 0), points[j]) / speed)

    print(ans)

    return


if __name__ == "__main__":
    main()
