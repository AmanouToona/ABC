import sys


def main():
    N, X, Y = map(int, sys.stdin.readline().strip().split())

    dp = [[0] * 2 for _ in range(N + 1)]  # dp: レベル, 色  0: red, 1: blue
    dp[N][0] = 1

    for level in range(N, 1, -1):
        # 赤色遷移
        dp[level - 1][0] += dp[level][0]
        dp[level][1] += dp[level][0] * X

        # 青色遷移
        dp[level - 1][0] += dp[level][1]
        dp[level - 1][1] += dp[level][1] * Y

    print(dp[1][1])

    return


if __name__ == "__main__":
    main()
