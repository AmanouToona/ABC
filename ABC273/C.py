import sys
from collections import defaultdict

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))

    A_ = list(set(A))
    A_.sort()

    convert = {}
    for i, a in enumerate(A_):
        convert[a] = len(A_) - i - 1

    ans = defaultdict(int)
    for a in A:
        ans[convert[a]] += 1

    for k in range(N):
        print(ans[k])

    return


if __name__ == "__main__":
    main()
