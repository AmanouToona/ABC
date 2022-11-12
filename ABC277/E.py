import sys
from collections import deque

sys.setrecursionlimit(10 ** 8)


def main():
    N, M, K = map(int, sys.stdin.readline().strip().split())

    g_on = [[] for _ in range(N)]
    g_off = [[] for _ in range(N)]
    for _ in range(M):
        u, v, a = map(int, sys.stdin.readline().strip().split())
        u -= 1
        v -= 1

        if a:
            g_on[u].append(v)
            g_on[v].append(u)
        else:
            g_off[u].append(v)
            g_off[v].append(u)

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
        if of:
            for v in g_on[u]:
                if dp[v][of] <= nxt_cost:
                    continue
                else:
                    dp[v][of] = nxt_cost
                    q.append((v, of))
        else:
            for v in g_off[u]:
                if dp[v][of] <= nxt_cost:
                    continue
                else:
                    dp[v][of] = nxt_cost
                    q.append((v, of))

        if u in s:
            if of:
                for v in g_off[u]:
                    if dp[v][0] <= nxt_cost:
                        continue
                    else:
                        dp[v][0] = nxt_cost
                        q.append((v, 0))

            else:
                for v in g_on[u]:
                    if dp[v][1] <= nxt_cost:
                        continue
                    else:
                        dp[v][1] = nxt_cost
                        q.append((v, 1))

    ans = min(dp[N - 1])

    if ans != float("inf"):
        print(ans)
    else:
        print(-1)

    return


if __name__ == "__main__":
    main()
