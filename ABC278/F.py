import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())

    S = []
    for _ in range(N):
        S.append(sys.stdin.readline().strip())

    # dp[state][n] := n を消費して 状態 state であるとき先攻が勝つなら1 後攻が勝つなら 0
    dp = [[-1] * N for _ in range(1 << N)]

    def win(u, state):
        if dp[state][u] != -1:
            return dp[state][u]

        can_win = []
        for v in range(N):
            if (state >> v) & 1:
                continue

            if S[u][-1] != S[v][0]:
                continue
            can_win.append(win(v, state=(state | 1 << v)))

        if not can_win:
            dp[state][u] = 1
        elif all(can_win):
            dp[state][u] = 0
        else:
            dp[state][u] = 1

        return dp[state][u]

    for n in range(N):
        if win(n, 1 << n):
            print("First")
            return

    print("Second")

    return


if __name__ == "__main__":
    main()
