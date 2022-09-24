import sys

sys.setrecursionlimit(10**8)


def main():
    N, X, Y = map(int, sys.stdin.readline().strip().split())

    g = [[] for _ in range(N)]

    for _ in range(N - 1):
        U, V = map(int, sys.stdin.readline().strip().split())

        U -= 1
        V -= 1

        g[U].append(V)
        g[V].append(U)

    ans = [X - 1]

    def dfs(u, p):
        if u == Y - 1:
            a = [f"{i + 1}" for i in ans]
            a = " ".join(a)
            print(a)
            sys.exit()

        for v in g[u]:
            if v == p:
                continue

            ans.append(v)
            dfs(v, u)
            if v == Y - 1:
                return
            ans.pop()

    dfs(X - 1, -1)

    return


if __name__ == "__main__":
    main()
