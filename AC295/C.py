import sys
from collections import defaultdict


sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))

    cnt = defaultdict(int)
    for a in A:
        cnt[a] += 1

    p = 0
    for _, val in cnt.items():
        p += val // 2

    print(p)

    return


if __name__ == "__main__":
    main()
