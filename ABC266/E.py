def main():
    N = int(input())

    dp = [-1] * (N + 1)  # dp[i]: i回サイコロを振ったとときの期待値

    for i in range(1, N + 1):  # i 回めにサイコロを振る
        tot = 0
        for roll in range(1, 7):
            if roll > dp[i - 1]:
                tot += roll
            else:
                tot += dp[i - 1]

        dp[i] = tot / 6

    print(dp[N])

    return


if __name__ == "__main__":
    main()
