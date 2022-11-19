import sys
from collections import defaultdict
sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())

    S = []
    frm = defaultdict(list)
    for n in range(N):
        s = sys.stdin.readline().strip()
        S.append(s)

        frm[ord(s[0]) - ord("a")].append(n)

    # dp[state][now use] = -1 未着手 0 負け確 1 勝確
    dp = [[-1] * N for _ in range(1 << N)]

    def dfs(u, state, first):
        if dp[u][state] != -1:
            return dp[u][state]

        s = S[u]
        f = ord(s[-1]) - ord("a")

        win = False
        for v in frm[f]:
            if dfs(v, state) == 1:
                win = True

        if win:
            dp[u][state] = 1
        else:

            dp[u][state] = -1
        return dp[u][state]

    for n in range(N):


    return


if __name__ == "__main__":
    main()
