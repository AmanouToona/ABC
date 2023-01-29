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


def main():
    N = int(input())

    B = [2 ** 61 - 1, 114514, 1919, 893, 364364]  # base
    M = [10 ** 9 + 7, 10 ** 9 + 7, 10 ** 9 + 7, 10 ** 9 + 7, 10 ** 9 + 7]  # mod

    S = []
    for _ in range(N):
        S.append(sys.stdin.readline().strip())

    return


if __name__ == "__main__":
    main()
