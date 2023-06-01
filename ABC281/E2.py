# https://atcoder.jp/contests/abc281/editorial/5387 を参考にした実装

import sys
import operator


class SegmentTree:
    def __init__(self, n: int, func=min, init_val=float("inf")) -> None:
        x = 1
        while x < n:
            x *= 2

        self.n = x  # 葉の数
        self.data = [init_val] * (2 * x - 1)  # データ

        self.func = func
        self.init_val = init_val
        return

    def update(self, i: int, x: int):
        i += self.n - 1
        self.data[i] = x

        while i > 0:
            i = (i - 1) // 2
            self.data[i] = self.func(self.data[i * 2 + 1], self.data[i * 2 + 2])
        return

    def query(self, a: int, b: int):
        # [a, b): 要求範囲
        return self._query(a, b, 0, 0, self.n)

    def _query(self, a: int, b: int, k: int, left: int, right: int):
        # [a, b) : 要求範囲
        # k: 現在のノード番号
        # [left, right): 探索範囲

        if b <= left or a >= right:
            return self.init_val

        if a <= left and right <= b:
            return self.data[k]

        value_left = self._query(a, b, k * 2 + 1, left, (left + right) // 2)
        value_right = self._query(a, b, k * 2 + 2, (left + right) // 2, right)

        return self.func(value_left, value_right)


class heap:
    # 要素への直接アクセスを可能とした heap
    def __init__(self, N) -> None:
        self.n = N
        # 最小値を管理する
        self.mini = SegmentTree(N, func=min, init_val=float("inf"))

        def f1(x, y):
            if x[1] <= y[1]:
                return x
            else:
                return y

        # idx を管理する
        self.idx = SegmentTree(N, func=f1, init_val=(-1, float("inf")))

        return

    def update(self, i, a):
        # idx i を a で更新する
        self.mini.update(i, a)
        self.idx.update(i, (i, a))
        return

    def pop(self):
        # 最小値を pop する

        idx, a = self.idx.query(0, self.n + 1)

        # 状態の更新
        self.idx.update(idx, (-1, float("inf")))
        self.mini.update(idx, float("inf"))

        return idx, a

    def feed(self):
        # 最小値を見る
        idx, a = self.idx.query(0, self.n + 1)

        return idx, a


def main():
    N, M, K = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    canuse = heap(N)  # 使用可能な数字の最小値を得る
    for i, a in enumerate(A[:M]):
        canuse.update(i, a)

    tot = 0
    using = heap(N)  # 使用の数値の -最大値 を得る
    using_cnt = SegmentTree(N, func=operator.add, init_val=0)  # 使用中の数字の個数を得る
    for _ in range(K):
        idx, a = canuse.pop()
        tot += a

        using.update(idx, -a)
        using_cnt.update(idx, 1)

    ans = [tot]
    for i, a in enumerate(A[M:]):
        # A[i] を利用不能な数字に変更する
        canuse.update(i, float("inf"))
        using.update(i, float("inf"))
        using_cnt.update(i, 0)

        # A[i] を利用していた場合の追加処理
        if using_cnt.query(0, N) == K - 1:
            tot -= A[i]

        # a を利用可能な数字に変更する
        canuse.update(i + M, a)

        # A[i] を利用していた場合
        if using_cnt.query(0, N) == K - 1:
            _i, _a = canuse.pop()
            using.update(_i, -a)
            using_cnt.update(_i, 1)

            tot += _a

        # 新たに a を利用した方がよい場合の追加処理
        if -using.feed()[1] > a:
            _i, _a = using.pop()

            tot -= _a
            tot += a

            canuse.update(_i, float("inf"))
            using.update(i + M, a)

        ans.append(tot)

    print(*ans)
    return


if __name__ == "__main__":
    main()
