import sys
from collections import defaultdict


def main():
    N, M = map(int, sys.stdin.readline().strip().split())
    X = list(map(int, sys.stdin.readline().strip().split()))

    bonus = defaultdict(int)

    for _ in range(M):
        c, y = map(int, sys.stdin.readline().strip().split())
        bonus[c] = y

    dp = [[0] * (N + 1) for _ in range(N + 1)]  # dp[i][j]  i: i回連続 j: j日目
    dp[1][1] = X[0] + bonus[1]

    for n in range(1, N):
        for j in range(n + 1):
            # front
            dp[j + 1][n + 1] = max(dp[j + 1][n + 1], dp[j][n] + X[n] + bonus[j + 1])

            # back
            dp[0][n + 1] = max(dp[j][n], dp[0][n + 1])

    ans = 0
    for d in dp:
        ans = max(ans, d[N])

    print(ans)

    return


if __name__ == "__main__":
    main()
