import sys

# 実装しなおす


def main():
    N, M = map(int, sys.stdin.readline().strip().split())
    X = list(map(int, sys.stdin.readline().strip().split()))

    bonus = dict()

    for _ in range(M):
        c, y = map(int, sys.stdin.readline().strip().split())
        bonus[c] = y

    dp = [[0] * N for _ in range(N + 1)]  # dp[i][j]  i 回連続 j - 1日目
    dp[1][0] = X[0]
    if 1 in bonus.keys():
        dp[1][0] += bonus[1]

    for n in range(N - 1):  # n + 2 日目 への遷移
        for j in range(n + 2):  # j連続からの遷移
            front = dp[j][n] + X[n + 1]
            if (j + 1) in bonus.keys():
                front += bonus[j + 1]

            dp[j + 1][n + 1] = max(dp[j + 1][n + 1], front)

            # back
            dp[0][n + 1] = max(dp[j][n], dp[0][n + 1])

    ans = 0
    for d in dp:
        ans = max(ans, d[N - 1])

    print(ans)

    return


if __name__ == "__main__":
    main()
