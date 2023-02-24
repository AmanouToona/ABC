import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    G = [[] for _ in range(N)]
    for _ in range(M):
        A, B = map(int, sys.stdin.readline().strip().split())
        A -= 1
        B -= 1
        G[A].append(B)
        G[B].append(A)

    global cnt
    cnt = 0
    used = [-1] * N

    def dfs(p, u):
        global cnt

        for v in G[u]:
            if v == p:
                continue
            if used[v] != -1:
                if used[v] < used[u]:
                    cnt += 1
                continue

            used[v] = used[u] + 1
            dfs(u, v)

    for u in range(N):
        if used[u] != -1:
            continue
        used[u] = 0
        dfs(-1, u)

    print(cnt)

    return


if __name__ == "__main__":
    main()
