import sys

MOD = 998244353


def main():
    N, M, K = map(int, sys.stdin.readline().strip().split())

    g = [[] * N]
    for _ in range(M):
        u, v = map(int, sys.stdin.readline().strip().split())
        u -= 1
        v -= 1
        g[u].append(v)
        g[v].append(u)

    return


if __name__ == "__main__":
    main()
