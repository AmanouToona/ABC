import sys

sys.setrecursionlimit(10**8)


class UnionFind:
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n  # 負値 :-size  正:parent を表す

    def find(self, x):  # root を返す
        if self.parents[x] < 0:
            return x
        else:
            return self.find(self.parents[x])

    def union(self, x, y):  # x, y を結合する
        x_root = self.find(x)
        y_root = self.find(y)

        if x_root == y_root:
            return

        if self.parents[x_root] > self.parents[y_root]:
            x_root, y_root = y_root, x_root

        self.parents[x_root] += self.parents[y_root]
        self.parents[y_root] = x_root

    def size(self, x):  # x が含まれる木のサイズを返す
        return -self.parents[self.find(x)]

    def same(self, x, y):  # x, y が同一の木に含まれるか返す
        return self.find(x) == self.find(y)

    def members(self, x):  # x を含む木に含まれるメンバーをかえす
        x_root = self.find(x)
        return [i for i in range(self.n) if self.find(i) == x_root]

    def roots(self):  # 根の一覧を返す
        return [i for i in range(self.n) if self.parents[i] < 0]


def main():
    # たぶん、与えられたグラフから関節点を抜き出して、関節点のみではられるグラフを作り、同一グラフに属しているか判定しすれば良い
    # 関節点的な点であり、関節点ではない

    N = int(input())

    G = [[] for _ in range(N)]

    for _ in range(N):
        u, v = map(int, sys.stdin.readline().strip().split())

        u -= 1
        v -= 1

        G[u].append(v)
        G[v].append(u)

    # 関節点の判定
    ord = [-1] * N
    low = [float("inf")] * N

    global count
    count = 0

    def dfs(u, p):
        global count
        ord[u] = count
        low[u] = min(low[u], ord[u])
        count += 1

        for v in G[u]:
            if ord[v] != -1:  # 訪問済み
                continue

            dfs(v, u)

        for v in G[u]:
            if v == p:
                continue
            low[u] = min(low[u], low[v])

        return

    dfs(0, -1)

    uf = UnionFind(N)

    for u in range(N):
        for v in G[u]:
            if low[v] <= ord[u]:
                continue

            uf.union(u, v)

    Q = int(input())
    for _ in range(Q):
        x, y = map(int, sys.stdin.readline().strip().split())

        x -= 1
        y -= 1

        if uf.same(x, y):
            print("Yes")
        else:
            print("No")

    return


if __name__ == "__main__":
    main()
