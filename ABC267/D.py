import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N, M = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    # dp[m][n] : m 個の数字を使用した n個まで見た ときの最大値
    dp = [[-float("inf")] * (N + 1) for _ in range(M + 1)]

    for n in range(N + 1):
        dp[0][n] = 0

    for m in range(1, M + 1):
        for n in range(1, N + 1):
            dp[m][n] = max(dp[m][n], dp[m][n - 1])
            dp[m][n] = max(dp[m][n], dp[m - 1][n - 1] + A[n - 1] * m)

    print(dp[M][N])

    return


if __name__ == "__main__":
    main()
