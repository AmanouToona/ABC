import sys

sys.setrecursionlimit(10 ** 8)


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
    N, Q = map(int, sys.stdin.readline().strip().split())

    cnt = N
    uf = UnionFind(10 ** 6)
    boxes = {i: i for i in range(N)}  # box i に入っている球  入っていない場合は -1

    for _ in range(Q):
        query = list(map(int, sys.stdin.readline().strip().split()))
        q = query[0]
        X = query[1] - 1

        if q == 3:
            root = uf.find(X)
            print(boxes[root] + 1, "*" * 10)

        Y = query[-1] - 1
        if q == 1:
            # box X が空
            if boxes[X] == -1:
                root_y = uf.find(Y)
                boxes[X] = root_y

            root_y = uf.find(Y)
            boxes[root_y] = X
            uf.union(X, Y)
        if q == 2:
            boxes[cnt] = boxes[uf.find(X)]
            uf.union(X, cnt)
            cnt += 1

    return


if __name__ == "__main__":
    main()
