import sys
from collections import deque

sys.setrecursionlimit(10 ** 8)


def main():
    N, M, K = map(int, sys.stdin.readline().strip().split())

    g = [[[] for _ in range(2)] for _ in range(N)]
    for _ in range(M):
        u, v, a = map(int, sys.stdin.readline().strip().split())
        u -= 1
        v -= 1

        g[u][a].append(v)
        g[v][a].append(u)

    s = list(map(int, sys.stdin.readline().strip().split()))
    s = set([i - 1 for i in s])

    # dp[i][j] := 位置 i  on/off状態 j  で最小手番でいる
    dp = [[float("inf")] * 2 for _ in range(N)]
    dp[0][1] = 0

    q = deque()
    q.append((0, 1))
    while q:
        u, of = q.popleft()

        nxt_cost = dp[u][of] + 1

        for v in g[u][of]:
            if dp[v][of] <= nxt_cost:
                continue
            dp[v][of] = nxt_cost
            q.append((v, of))

        if u in s:
            for v in g[u][1 - of]:
                if dp[v][1 - of] <= nxt_cost:
                    continue
                dp[v][1 - of] = nxt_cost
                q.append((v, 1 - of))

    ans = min(dp[N - 1])

    if ans != float("inf"):
        print(ans)
    else:
        print(-1)

    return


if __name__ == "__main__":
    main()
