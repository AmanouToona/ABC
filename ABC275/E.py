import sys

sys.setrecursionlimit(10 ** 8)

MOD = 998244353


def pow(x, y, mod=MOD):

    if y == -1:
        y = mod - 2

    res = 1
    xx = x
    while y > 0:

        if y & 1:
            res *= xx
        if mod:
            res %= mod

        y >>= 1

        xx *= xx
        if mod:
            xx %= mod

    return res


def main():
    N, M, K = map(int, sys.stdin.readline().strip().split())

    inv_M = pow(M, MOD - 2)

    # dp[i][j]: = i回目に j にいる確率mod
    dp = [[0] * (N + 1) for _ in range(K + 1)]
    dp[0][0] = 1

    for i in range(K):
        for j in range(N):
            for m in range(1, M + 1):
                nxt = j + m
                if nxt > N:
                    nxt = N - (nxt - N)

                dp[i + 1][nxt] += dp[i][j] * inv_M
                dp[i + 1][nxt] %= MOD

    ans = 0
    for i in range(K + 1):
        ans += dp[i][N]
        ans %= MOD

    print(ans)

    return


if __name__ == "__main__":
    main()
