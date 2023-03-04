import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    g = [[] for _ in range(N)]
    rg = [[] for _ in range(N)]
    into = [0] * N
    edges = set()
    for _ in range(M):
        u, v = map(int, sys.stdin.readline().strip().split())
        u -= 1
        v -= 1
        g[u].append(v)
        rg[v].append(u)
        edges.add((u, v))

        into[v] += 1

    global stack
    stack = []
    done = [False] * N

    def dfs(u):
        global stack
        done[u] = True
        stack.append(u)

        for v in g[u]:
            if done[v]:
                continue
            dfs(v)

    cnt = 0

    for i, num in enumerate(into):
        if num != 0:
            continue
        stack = []

        dfs(i)

        for i in range(len(stack)):
            for j in range(i + 1, len(stack)):
                if (stack[i], stack[j]) not in edges:
                    cnt += 1

    print(cnt)

    return


if __name__ == "__main__":
    main()
