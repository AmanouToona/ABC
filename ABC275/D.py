import sys
from math import floor

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())

    memo = dict()
    memo[0] = 1

    def f(k):
        if k in memo.keys():
            return memo[k]

        res = f(floor(k / 2)) + f(floor(k / 3))
        memo[k] = res
        return memo[k]

    print(f(N))

    return


if __name__ == "__main__":
    main()
