# rolling hash version

import sys
from collections import defaultdict

sys.setrecursionlimit(10 ** 8)


class RollingHash:
    def __init__(self, s: str, b: int, m: int) -> None:
        self.s = s
        self.b = b
        self.m = m

        self.h = [0] * (len(s) + 1)
        self.b_pow = [1] * (len(s) + 1)

        for i, c in enumerate(s):
            self.h[i + 1] = ord(c) * self.b + self.h[i] * self.b
            self.h[i + 1] %= self.m

            self.b_pow[i + 1] *= self.b_pow[i] * self.b
            self.b_pow[i + 1] %= self.m

        return

    def get(self, left, right) -> int:
        # [left, right)
        res = (self.h[right] - self.h[left] * self.b_pow[right - left]) % self.m

        return res


class StableRollingHash:
    # 複数の base, mod によるハッシュを返すクラス
    def __init__(self, s, b, m) -> None:
        self.rollings = []

        for b_, m_ in zip(b, m):
            self.rollings.append(RollingHash(s, b_, m_))

        return

    def get(self, left, right) -> int:
        res = []
        for rolling in self.rollings:
            res.append(rolling.get(left, right))

        return tuple(res)


def main():
    N = int(input())

    B = [2 ** 61 - 1, 114514, 1919, 893, 364364]  # base
    M = [10 ** 9 + 7, 10 ** 9 + 7, 10 ** 9 + 7, 10 ** 9 + 7, 10 ** 9 + 7]  # mod

    S = []
    for _ in range(N):
        S.append(sys.stdin.readline().strip())

    h = defaultdict(int)

    for s in S:
        stablehash = StableRollingHash(s, B, M)
        for right in range(1, len(s) + 1):
            h[stablehash.get(0, right)] += 1

    for s in S:
        stablehash = StableRollingHash(s, B, M)

        ans = 0

        for right in range(1, len(s) + 1):
            if h[stablehash.get(0, right)] > 1:
                ans = right

        print(ans)

    return


if __name__ == "__main__":
    main()
