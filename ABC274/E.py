import sys
from math import sqrt

sys.setrecursionlimit(10**8)


def get_dist(point1, point2):
    res = sqrt((point1[0] - point2[0]) ** 2 + (point1[1] - point2[1]) ** 2)
    return res


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    point = [(0, 0)]
    for _ in range(N):
        x, y = map(int, sys.stdin.readline().strip().split())
        point.append((x, y))

    for _ in range(M):
        p, q = map(int, sys.stdin.readline().strip().split())
        point.append((p, q))

    dp = [[float("inf")] * (N + M + 1) for _ in range(1 << (N + M + 1))]
    dp[0][N + M] = 0

    point.reverse()

    ans = float("inf")
    # 状態は 街 宝箱 の順番
    for s in range(1 << (N + M + 1)):
        for v in range(N + M + 1):
            for u in range(N + M + 1):
                if u == v:
                    continue
                if (s >> u) & 1 == 0 and s != 0:
                    continue
                if (s >> v) & 1:
                    continue

                speed = 1
                for i in range(M):
                    if (s >> i) & 1:
                        speed *= 2

                dist = get_dist(point[u], point[v])
                time = dist / speed

                if v == N + M:
                    is_goal = True
                else:
                    is_goal = False
                for i in range(N + M - 1, M - 1, -1):
                    if not is_goal:
                        break
                    if not (s >> i) & 1:
                        is_goal = False
                        break

                if is_goal:
                    ans = min(ans, dp[s][u] + time)

                dp[s | (1 << v)][v] = min(dp[s | (1 << v)][v], dp[s][u] + time)

    print(ans)

    return


if __name__ == "__main__":
    main()
