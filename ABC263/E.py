import sys

sys.setrecursionlimit(10**8)


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

    cusum = [0] * (N + 2)  # 後ろからの期待値の累積和
    dp = [-1] * (N + 1)
    dp[N] = 0

    def solve(x):
        if dp[x] != -1:
            cusum[x] = dp[x] + cusum[x + 1]
            cusum[x] %= MOD
            return dp[x]

        if dp[x + 1] == -1:
            solve(x + 1)

        left = x + 1
        right = min(x + A[x] + 1, N + 1)

        res = cusum[left] - cusum[right]
        res += MOD
        res %= MOD

        inv_A = pow(A[x], -1, MOD)

        res *= inv_A
        res %= MOD

        res += 1 + inv_A
        res %= MOD

        dp[x] = res
        cusum[x] = dp[x] + cusum[x + 1]
        cusum[x] %= MOD

        return dp[x]

    ans = solve(1)
    print(ans)

    return


if __name__ == "__main__":
    main()
