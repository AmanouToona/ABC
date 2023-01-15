# pypy では TLE python で通すこと

import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    g = [[] for _ in range(N)]
    for _ in range(M):
        u, v = map(int, sys.stdin.readline().strip().split())
        u -= 1
        v -= 1
        g[u].append(v)
        g[v].append(u)

    global cnt
    cnt = 1
    used = [False] * N
    used[0] = True

    def dfs(p):
        global cnt

        for v in g[p]:
            if cnt >= 10 ** 6:
                return
            if used[v]:
                continue
            used[v] = True
            cnt += 1
            dfs(v)
            used[v] = False
        return

    dfs(0)
    print(cnt)

    return


if __name__ == "__main__":
    main()
