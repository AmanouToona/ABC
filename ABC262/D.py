import sys

MOD = 998244353


def main():
    N = int(sys.stdin.readline().strip())
    A = list(map(int, sys.stdin.readline().strip().split()))

    # dp [m 個選んだ][n][%n] の個数
    dp = [[[0] * (N + 1) for _ in range(N + 1)] for _ in range(N + 1)]

    for n in range(N + 1):
        dp[0][n][0] = 1

    for a in A:
        for m in range(N - 1, -1, -1):
            for n in range(1, N + 1):
                for rem in range(n):
                    # print(f"{m + 1}, {n=} {(rem + a) % n=} {rem=}")
                    dp[m + 1][n][(rem + a) % n] += dp[m][n][rem]
                    dp[m + 1][n][(rem + a) % n] %= MOD

    ans = 0
    for m in range(1, N + 1):
        ans += dp[m][m][0]
        ans %= MOD

    print(ans)

    return


if __name__ == "__main__":
    main()
