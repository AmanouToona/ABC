import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N, _ = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    dp = [-1] * (10 ** 4 + 1)
    dp[0] = 0

    def stone(n):
        if dp[n] != -1:
            return dp[n]

        ans = float("inf")
        for a in A:
            if n - a >= 0:
                ans = min(ans, stone(n - a))

        dp[n] = n - ans
        return dp[n]

    stone(N)

    print(dp[N])

    return


if __name__ == "__main__":
    main()
