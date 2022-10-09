import sys
from math import ceil

sys.setrecursionlimit(10 ** 8)


def main():
    N, M = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    check = [[] for _ in range(M)]
    for i, a in enumerate(A):
        if a > N:
            continue

        start = max(0, ceil(-a / (i + 1)) - 1)
        a_ = a + start * (i + 1)
        j = start
        while a_ + (i + 1) < N and j < M:
            a_ += i + 1
            check[j].append(a_)
            j += 1

    for c in check:
        search = [False] * (len(c) + 1)

        for c_ in c:
            if c_ >= len(search):
                continue
            search[c_] = True

        for i, s in enumerate(search):
            if s:
                continue
            print(i)
            break

    return


if __name__ == "__main__":
    main()
