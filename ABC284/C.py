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

    cnt = 0
    used = [False] * N
    for i in range(N):
        if used[i]:
            continue
        cnt += 1

        q = []
        q.append(i)
        used[i] = True
        while q:
            u = q.pop()

            for v in g[u]:
                if used[v]:
                    continue
                q.append(v)
                used[v] = True

    print(cnt)

    return


if __name__ == "__main__":
    main()
