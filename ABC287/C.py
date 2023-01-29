import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    graph = [[] for _ in range(N)]

    deg = [0] * N
    for _ in range(M):
        u, v = map(int, sys.stdin.readline().strip().split())
        u -= 1
        v -= 1

        graph[u].append(v)
        graph[v].append(u)

        deg[u] += 1
        deg[v] += 1

    start = None
    for i, d in enumerate(deg):
        if d == 1:
            start = i
            break

    if start is None:
        print("No")
        return

    used = [False] * N
    used[start] = True

    now = start
    while True:
        nxt = None
        for v in graph[now]:
            if used[v]:
                continue
            nxt = v
            break

        if nxt is None:
            break

        used[nxt] = True
        now = nxt

    if all(used):
        print("Yes")
    else:
        print("No")

    return


if __name__ == "__main__":
    main()
