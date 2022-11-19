import sys
from collections import defaultdict

sys.setrecursionlimit(10 ** 8)


def main():
    _ = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))
    Q = int(input())

    base = 0
    addition = defaultdict(int)

    for i, a in enumerate(A):
        addition[i] = a

    for _ in range(Q):
        query = list(map(int, sys.stdin.readline().strip().split()))

        if query[0] == 1:
            base = query[1]
            addition = defaultdict(int)
        elif query[0] == 2:
            i = query[1] - 1
            x = query[2]
            addition[i] += x
        else:
            i = query[1] - 1
            print(base + addition[i])

    return


if __name__ == "__main__":
    main()
