import sys
from collections import defaultdict

sys.setrecursionlimit(10 ** 8)


def main():
    N, Q = map(int, sys.stdin.readline().strip().split())

    follow = defaultdict(set)

    for _ in range(Q):
        T, A, B = map(int, sys.stdin.readline().strip().split())

        if T == 1:
            follow[A].add(B)
        if T == 2:
            if B in follow[A]:
                follow[A].remove(B)
        if T == 3:
            if B in follow[A] and A in follow[B]:
                print("Yes")
            else:
                print("No")

    return


if __name__ == "__main__":
    main()
