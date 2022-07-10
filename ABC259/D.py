import sys


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


def is_touch(c1, c2):
    x1, y1, r1 = c1
    x2, y2, r2 = c2

    d2 = (x1 - x2) ** 2 + (y1 - y2) ** 2

    if (r1 + r2) ** 2 < d2:
        return False

    if d2 < (max(r1, r2) - min(r1, r2)) ** 2:
        return False

    return True


def main():
    N = int(input())
    sx, sy, tx, ty = map(int, sys.stdin.readline().strip().split())

    circle = []
    for _ in range(N):
        circle.append(list(map(int, sys.stdin.readline().strip().split())))

    uf = UnionFind(N)

    for i in range(N - 1):
        for j in range(i + 1, N):
            if is_touch(circle[i], circle[j]):
                uf.union(i, j)

    starts = []
    ends = []
    for i in range(N):
        x, y, r = circle[i]

        if (x - sx) ** 2 + (y - sy) ** 2 == r ** 2:
            starts.append(i)

        if (x - tx) ** 2 + (y - ty) ** 2 == r ** 2:
            ends.append(i)

    for s in starts:
        for t in ends:
            if uf.same(s, t):
                print("Yes")
                return

    print("No")

    return


if __name__ == "__main__":
    main()
