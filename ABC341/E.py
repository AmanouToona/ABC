import sys

sys.setrecursionlimit(10**8)


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

    def get(self, x):
        return self.data[x + self.n - 1]

    def query(self, a: int, b: int):
        return self._query(a, b, 0, 0, self.n)

    def _query(self, a: int, b: int, k: int, left: int, right: int):
        # [a, b) : 要求範囲
        # k: 現在のノード番号
        # [left, right): 探索範囲

        if b <= left or a >= right:
            return 0

        if a <= left and right <= b:
            return self.data[k]

        value_left = self._query(a, b, k * 2 + 1, left, (left + right) // 2)
        value_right = self._query(a, b, k * 2 + 2, (left + right) // 2, right)

        return value_left + value_right


def main():
    N, Q = map(int, sys.stdin.readline().strip().split())
    S = input()

    seg = SegmentTree(len(S))

    for i, s in enumerate(S):
        if i == 0:
            continue
        if s == S[i - 1]:
            seg.update(i, 1)

    for _ in range(Q):
        q, L, R = map(int, sys.stdin.readline().strip().split())
        L -= 1
        R -= 1

        if q == 1:
            if L != 0:
                seg.update(L, 1 - seg.get(L))
            if R + 1 <= len(S) - 1:
                seg.update(R + 1, 1 - seg.get(R + 1))

        else:
            ans = seg.query(L + 1, R + 1)
            if ans == 0:
                print("Yes")
            else:
                print("No")

    return


if __name__ == "__main__":
    main()

"""
5 6
10100
2 1 3
2 1 5
1 1 4
2 1 5
1 3 3
2 2 4
"""
