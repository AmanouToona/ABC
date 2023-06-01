import sys
from collections import deque

sys.setrecursionlimit(10**8)


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    g = [[] for _ in range(N + M)]
    for i in range(N):
        _ = sys.stdin.readline()
        S = list(map(int, sys.stdin.readline().strip().split()))

        for s in S:
            s -= 1
            g[i].append(s + N)
            g[s + N].append(i)

    q = deque()
    q.append(N + 0)
    fp = [-2] * (N + M)  # foot print
    fp[N + 0] = -1

    while q:
        u = q.popleft()

        for v in g[u]:
            if fp[v] != -2:
                continue
            q.append(v)
            fp[v] = fp[u] + 1

            if v == N + M - 1:
                print(fp[v] // 2)

                return

    print(-1)
    return


if __name__ == "__main__":
    main()
