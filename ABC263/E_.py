import sys

sys.setrecursionlimit(10 ** 8)


def pow(x, y, mod=None):

    if y == -1:
        y = mod - 2

    res = 1

    xx = x
    while y > 0:

        if y & 1:
            res *= xx

        if mod:
            res %= mod
            xx %= mod

        y >>= 1

        xx *= xx
    return res


MOD = 998244353


def main():
    N = int(input())
    A = [0]
    A.extend(list(map(int, sys.stdin.readline().strip().split())))

    dp = [-1] * (N + 1)
    dp[N] = 0

    def solve(x):
        if dp[x] != -1:
            return dp[x]

        res = 0
        for i in range(1, A[x] + 1):
            if x + i > N:
                continue
            res += solve(x + i)
            res %= MOD

        inv_Ax = pow(A[x], -1, MOD)

        res *= inv_Ax
        res %= MOD
        res += inv_Ax + 1
        res %= MOD

        dp[x] = res

        return dp[x]

    ans = solve(1)
    print(ans)

    return


if __name__ == "__main__":
    main()
