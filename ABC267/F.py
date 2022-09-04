import sys
from collections import deque

sys.setrecursionlimit(10 ** 8)


def main():
    input = sys.stdin.readline
    N = int(input())

    G = [[] for _ in range(N)]
    for _ in range(N - 1):
        A, B = map(int, input().strip().split())
        A -= 1
        B -= 1

        G[A].append(B)
        G[B].append(A)

    def bfs(s):
        dist = [-1] * N
        que = deque([s])
        dist[s] = 0
        while que:
            v = que.popleft()
            d = dist[v]
            for w in G[v]:
                if dist[w] >= 0:
                    continue
                dist[w] = d + 1
                que.append(w)
        d = max(dist)
        return dist.index(d)

    # 木の直径の両端A, Bを求める
    A = bfs(0)
    B = bfs(A)

    # ダブリングで祖先管理
    K = 0
    while (1 << K) <= N:
        K += 1

    # A祖先
    parentsa = [[-1] * N for _ in range(K)]  # parentsa[K][N]:= N の 2 ** K 個先の祖先 根はA

    def dfs_a(u, p):
        parentsa[0][u] = p

        for v in G[u]:
            if v == p:
                continue
            dfs_a(v, u)

    dfs_a(A, -1)

    for k in range(1, K):
        for n in range(N):
            if parentsa[k - 1][n] == -1:
                parentsa[k][n] = -1
                continue
            parentsa[k][n] = parentsa[k - 1][parentsa[k - 1][n]]

    # B祖先
    parentsb = [[-1] * N for _ in range(K)]  # parentsb[K][N]:= N の 2 ** K 個先の祖先 根はB

    def dfs_b(u, p):
        parentsb[0][u] = p

        for v in G[u]:
            if v == p:
                continue
            dfs_b(v, u)

    dfs_b(B, -1)

    for k in range(1, K):
        for n in range(N):
            if parentsb[k - 1][n] == -1:
                parentsb[k][n] = -1
                continue
            parentsb[k][n] = parentsb[k - 1][parentsb[k - 1][n]]

    Q = int(input())
    for _ in range(Q):
        U, K = map(int, input().strip().split())

        U -= 1

        k = []
        count = 0
        while 1 << count <= K:
            if (1 << count) & K:
                k.append(count)
            count += 1

        now_a = U
        now_b = U
        for _k in k:
            if now_a != -1:
                now_a = parentsa[_k][now_a]
            if now_b != -1:
                now_b = parentsb[_k][now_b]

        if now_a != -1:
            print(now_a + 1)
        elif now_b != -1:
            print(now_b + 1)
        else:
            print(-1)

    return


if __name__ == "__main__":
    main()
