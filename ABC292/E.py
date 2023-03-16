import sys
from collections import deque

sys.setrecursionlimit(10 ** 8)


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    g = [[] for _ in range(N)]
    edges = set()
    for _ in range(M):
        u, v = map(int, sys.stdin.readline().strip().split())
        u -= 1
        v -= 1
        g[u].append(v)
        edges.add((u, v))

    global ans
    ans = 0

    def bfs(p):
        global ans
        q = deque()
        used = [False] * N
        used[p] = True

        for u in g[p]:
            q.append(u)
            used[u] = True

        while q:
            u = q.popleft()
            if (p, u) not in edges:
                ans += 1

            for v in g[u]:
                if used[v]:
                    continue
                q.append(v)
                used[v] = True

    for i in range(N):
        bfs(i)

    print(ans)

    return


if __name__ == "__main__":
    main()
