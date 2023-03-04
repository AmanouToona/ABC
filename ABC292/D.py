import sys
from collections import defaultdict

sys.setrecursionlimit(10 ** 8)


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    g = [[] for _ in range(N)]
    edges = defaultdict(int)
    for _ in range(M):
        u, v = map(int, sys.stdin.readline().strip().split())
        u -= 1
        v -= 1
        g[u].append(v)
        g[v].append(u)
        edges[(u, v)] += 1
        if u != v:
            edges[(v, u)] += 1

    used_n = [False] * N

    def dfs(u):
        cnt_e = 0
        cnt_n = 0

        for v in g[u]:
            if used_n[v]:
                cnt_e += edges[(u, v)]
                edges[(u, v)] = 0
                edges[(v, u)] = 0
                continue

            used_n[v] = True
            cnt_n += 1

            cnt_e += edges[(u, v)]
            edges[(u, v)] = 0
            edges[(v, u)] = 0

            _e, _n = dfs(v)
            cnt_e += _e
            cnt_n += _n

        return cnt_e, cnt_n

    for i in range(N):
        if used_n[i]:
            continue
        used_n[i] = True
        e, n = dfs(i)

        if e != n + 1:
            print("No")
            return
    print("Yes")


if __name__ == "__main__":
    main()
