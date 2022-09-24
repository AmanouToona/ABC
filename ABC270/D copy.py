import sys

sys.setrecursionlimit(10**8)


def main():
    N, _ = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    # dp[t][r] = t ターン で 残り r このときの高橋くんの取得石の最大値
    dp = [[-float("inf")] * 10**4 for _ in range(2)]
    dp[]

    for r in range(10**4, -1, -1):
        for t in range(2):
            for a in A:
                if r - a < 0:
                    break
                dp[r - a][1 - t] = max(dp[r][t] + a, dp[r - a][1 - t])

    print(dp[0][1])

    return


if __name__ == "__main__":
    main()
