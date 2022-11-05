import sys


def pow(x, y, mod=998244353):

    if y == -1:
        y = mod - 2

    res = 1
    xx = x
    while y > 0:

        if y & 1:
            res *= xx
        if mod:
            res %= mod

        y >>= 1

        xx *= xx
        if mod:
            xx %= mod

    return res


class SegmentTree:
    def __init__(self, n: int) -> None:
        x = 1
        while x < n:
            x *= 2

        self.n = x  # 葉の数
        self.data = [0] * (2 * x - 1)  # データ
        return

    def update(self, i: int, x: int):
        i += self.n - 1
        self.data[i] = x

        while i > 0:
            i = (i - 1) // 2
            self.data[i] = self.data[i * 2 + 1] + self.data[i * 2 + 2]
        return

    def query(self, a: int, b: int):
        return self._query(a, b, 0, 0, self.n)

    def _query(self, a: int, b: int, k: int, left: int, right: int):
        # [a, b) : 要求範囲
        # k: 現在のノード番号
        # [left, right): 探索範囲

        if b <= left or a >= right:
            return float("inf")

        if a <= left and right <= b:
            return self.data[k]

        value_left = self._query(a, b, k * 2 + 1, left, (left + right) // 2)
        value_right = self._query(a, b, k * 2 + 2, (left + right) // 2, right)

        return value_left + value_right


sys.setrecursionlimit(10 ** 8)

MOD = 998244353


def main():
    _ = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))

    seg = SegmentTree(max(A) + 1)

    E = 0
    for k, a in enumerate(A):
        inv = pow(k + 1, MOD - 2)
        inv *= inv
        inv %= MOD

        x = (k - 1) ** 2 * inv
        x %= MOD

        z = A[k] * inv

        y = seg.query(0, a) * a + E * (k - seg(0, a))


        E = x + y + z
        E %= MOD
        print(E)

    return


if __name__ == "__main__":
    main()
