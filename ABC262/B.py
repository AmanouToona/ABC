import sys


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    g = [set() for _ in range(N)]
    for _ in range(M):
        u, v = map(int, sys.stdin.readline().strip().split())
        u -= 1
        v -= 1
        g[u].add(v)
        g[v].add(u)

    ans = 0
    for a in range(N):
        for b in range(a + 1, N):
            for c in range(b + 1, N):
                if b not in g[a]:
                    continue
                if c not in g[b]:
                    continue
                if a not in g[c]:
                    continue
                ans += 1

    print(ans)

    return


if __name__ == "__main__":
    main()
