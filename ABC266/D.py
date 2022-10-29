import sys


def main():
    N = int(input())

    XA = [None] * (10 ** 5 + 1)  # 時刻 T のすぬけ君の出現条法

    for _ in range(N):
        t, x, a = map(int, sys.stdin.readline().strip().split())
        XA[t] = (x, a)

    # 動的計画方
    dp = [[-float("inf")] * (10 ** 5 + 1) for _ in range(5)]  # dp[位置][時刻] でのすぬけ君合計値の最大
    dp[0][0] = 0  # 時刻 0 は 位置 0 にいる

    # 配る dp
    for t in range(10 ** 5):  # 時間
        for p in range(5):  # 位置
            if dp[p][t] < 0:
                continue

            for move in [-1, 0, 1]:
                if p + move < 0 or p + move >= 5:
                    continue

                tot = dp[p][t]

                if XA[t + 1] is not None:
                    x, a = XA[t + 1]

                    if x == p + move:
                        tot += a

                dp[p + move][t + 1] = max(tot, dp[p + move][t + 1])

    ans = 0
    for i in range(5):
        ans = max(ans, dp[i][10 ** 5])

    print(ans)

    return


if __name__ == "__main__":
    main()
