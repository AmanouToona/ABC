import sys
from math import sqrt

sys.setrecursionlimit(10 ** 8)


def main():
    A, B = map(int, sys.stdin.readline().strip().split())

    def calcT(x):
        return A / sqrt(1 + x) + B * x

    # 3 分探索
    left = 0
    right = 10 ** 18 + 1

    while right - left > 3:
        diff = (right - left) // 3
        c1 = left + diff
        c2 = right - diff

        if calcT(c1) > calcT(c2):
            left = c1
        else:
            right = c2

    ans = float("inf")
    for i in range(left, right + 1):
        ans = min(ans, calcT(i))

    print(f"{ans:.7f}")

    return


if __name__ == "__main__":
    main()
