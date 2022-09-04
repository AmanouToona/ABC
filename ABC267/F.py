import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())

    G = [[] for _ in range(N)]
    for _ in range(N - 1):
        A, B = map(int, sys.stdin.readline().strip().split())
        A -= 1
        B -= 1

        G[A].append(B)
        G[B].append(A)

    def furthest_point(u):
        N = len(G)
        dist = [-1] * N

        def dfs(u, p, d):
            dist[u] = d

            for v in G[u]:
                if v == p:
                    continue
                dfs(v, u, d + 1)

        dfs(u, -1, 0)

        max_dist = -float("inf")
        res = -1
        for i, d in enumerate(dist):
            if d > max_dist:
                res = i
                max_dist = d

        return res

    # 木の直径の両端A, Bを求める
    A = furthest_point(0)
    B = furthest_point(A)

    # ダブリングで祖先管理
    K = 0
    while 2 ** K <= N:
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
        U, K = map(int, sys.stdin.readline().strip().split())

        U -= 1

        # A を根とする木で Uからの距離が K である頂点を探索する
        now = U
        k = 0
        while (1 << k) <= K:
            if (1 << k) & K:
                now = parentsa[k][now]
                if now == -1:
                    break
            k += 1

        if now != -1:
            print(now + 1)
            continue

        # B を根とする木で Uからの距離が K である頂点を探索する
        now = U
        k = 0
        while (1 << k) <= K:
            if (1 << k) & K:
                now = parentsb[k][now]
                if now == -1:
                    break

            k += 1

        if now != -1:
            print(now + 1)
            continue

        print(now)

    return


if __name__ == "__main__":
    main()
