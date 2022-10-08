import sys
from math import ceil

sys.setrecursionlimit(10 ** 8)


def main():
    N, M = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    final = A.copy()
    for i in range(N):
        final[i] += (i + 1) * M

    zero = []
    for i, a in enumerate(final):
        t = ceil(max(-1, a) / (i + 1))
        res = a - (t - 1) * (i + 1)

        zero.append((t, res, i))

    zero.sort()

    ans = []
    s = 0
    for i in range(N):
        if zero[s][0] > i:
            ans.append[0]
            continue

        if zero[s][1] - (zero[s][2] + 1) != 0:
            ans.append[0]
        while s + 1 < N and zero[s + 1][0] <= i:
            s += 1

    return


if __name__ == "__main__":
    main()
